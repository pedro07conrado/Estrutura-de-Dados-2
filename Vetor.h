#include <iostream>
#include <string>
using namespace std;
class Vetor{
    private:
        int* vet;
        int tam;
        int qtd;

    void verificaAumenta(){
        this->tam*=2;
        int * aux = new int[this->tam];
        for(int i = 0; i < this->qtd; i++){
             aux[i] = this->vet[i];
        }
        delete this->vet;
        this->vet = aux;
    }

    public:
        Vetor();    
        ~Vetor();    
        void anexar(int elemento);
        bool inserir(int elemento, int posicao);
        bool substituir(int posicao, int elemento);
        int removerPorElemento(int elemento);
        bool removerPorPosicao(int posicao, int &removido);
        int tamanho();
        int buscarPorElemento(int elemento);
        int buscarPorPosicao(int posicao);
        void imprimir();
        std::string toString();

};