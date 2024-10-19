#include "thed.h"
#include <iostream>
#include <list>
#include <stdexcept>

TabHashEncadeamento::TabHashEncadeamento(int tamanho, int limiar)
    : m(tamanho), n(0), limiar(limiar), redims(0), invalido(std::make_pair(-1, -1)) {
    tabela = new std::vector<std::pair<int, int>>[m];
}

TabHashEncadeamento::~TabHashEncadeamento() {
    delete[] tabela;
}

int TabHashEncadeamento::hash(int chave) {
    return chave % m; // Função hash simples (mod m)
}

void TabHashEncadeamento::inserir(int chave, int valor) {
    int indice = hash(chave);
    // Verifica se a chave já existe e atualiza o valor se necessário
    for (auto& par : tabela[indice]) {
        if (par.first == chave) {
            par.second = valor;
            return;
        }
    }
    // Insere o novo par chave-valor
    tabela[indice].push_back(std::make_pair(chave, valor));
    n++;
    
    // Verifica o fator de carga e redimensiona, se necessário
    if (n / m > limiar) {
        redimensionar(m * 2);
    }
}

void TabHashEncadeamento::remover(int chave) {
    int indice = hash(chave);
    for (auto it = tabela[indice].begin(); it != tabela[indice].end(); ++it) {
        if (it->first == chave) {
            tabela[indice].erase(it);
            n--;
            return;
        }
    }
}

std::pair<int, int>& TabHashEncadeamento::buscar(int chave) {
    int indice = hash(chave);
    for (auto& par : tabela[indice]) {
        if (par.first == chave) {
            return par;
        }
    }
    return invalido; // Se a chave não for encontrada, retorna o par inválido
}

void TabHashEncadeamento::imprimir() {
    for (int i = 0; i < m; i++) {
        std::cout << "[" << i << "]";
        for (auto& par : tabela[i]) {
            std::cout << " -> (" << par.first << ", " << par.second << ")";
        }
        std::cout << std::endl;
    }
}

void TabHashEncadeamento::imprimir_info() {
    std::cout << "Tamanho da tabela (m): " << m << std::endl;
    std::cout << "Número de elementos (n): " << n << std::endl;
    std::cout << "Fator de carga: " << (float)n / m << std::endl;
    std::cout << "Número de redimensionamentos: " << redims << std::endl;
}

std::vector<int> TabHashEncadeamento::chaves() {
    std::vector<int> todas_chaves;
    for (int i = 0; i < m; i++) {
        for (auto& par : tabela[i]) {
            todas_chaves.push_back(par.first);
        }
    }
    return todas_chaves;
}

std::vector<std::pair<int, int>> TabHashEncadeamento::itens() {
    std::vector<std::pair<int, int>> todos_itens;
    for (int i = 0; i < m; i++) {
        for (auto& par : tabela[i]) {
            todos_itens.push_back(par);
        }
    }
    return todos_itens;
}

void TabHashEncadeamento::redimensionar(int novo_m) {
    std::vector<std::pair<int, int>>* nova_tabela = new std::vector<std::pair<int, int>>[novo_m];

    // Reinsere os elementos na nova tabela
    for (int i = 0; i < m; i++) {
        for (auto& par : tabela[i]) {
            int novo_indice = par.first % novo_m;
            nova_tabela[novo_indice].push_back(par);
        }
    }

    delete[] tabela;
    tabela = nova_tabela;
    m = novo_m;
    redims++;
}
