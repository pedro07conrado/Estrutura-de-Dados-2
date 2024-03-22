#include "Vetor.h"
#include <iostream>
#include <string>
using namespace std;
const int TAM = 5;
Vetor::Vetor(){
   this->vet = new int[TAM];
   this->tam = TAM;
   this->qtd = 0;
}
Vetor::~Vetor(){
    delete this->vet;
}
 void Vetor::anexar(int elemento){
    if(this->qtd == this->tam){
       verificaAumenta();
    }
    this->vet[this->qtd++] = elemento;
 }
 bool Vetor::inserir(int elemento, int posicao){
      if(posicao > this->qtd) return false;

      if(this->qtd == this->tam){
        verificaAumenta();
       }

        int aux;
        this->qtd++;
        for(int i = this->qtd; i > posicao; i--){
              this->vet[i] = this->vet[i-1];
        }
        this->vet[posicao] = elemento;
        return true;
 }
  bool Vetor::substituir(int posicao, int elemento){
         if(posicao > this->qtd) return false;
          this->vet[posicao] = elemento;
           return true;
  }
   bool Vetor::removerPorPosicao(int posicao, int &removido){
         if(posicao > this->qtd) return false;
         removido = this->vet[posicao];
           for(int i = posicao; i < this->qtd; i++){
               this->vet[i] = this->vet[i+1];
           }
           this->qtd--;
         return true;
    }
   int Vetor::removerPorElemento(int elemento){
      int guardar = -1;
       for(int i = 0; i < this->qtd; i++){
            if(this->vet[i] == elemento){
                 guardar = i;
            }
       }
       if(guardar == -1){
           return guardar;
       }else{
        removerPorPosicao(guardar, elemento);
        return guardar;
       }
   }
   int Vetor::tamanho(){
        return this->qtd;
   }
   int Vetor::buscarPorElemento(int elemento){
       int guardar = -1;
       for(int i = 0; i < this->qtd; i++){
            if(this->vet[i] == elemento){
                 guardar = i;
            }
       }
       if(guardar == -1){
           return guardar;
       }else{
         return guardar;
       }
   }
    int Vetor::buscarPorPosicao(int posicao){
          if(posicao > this->qtd || posicao < 0){
            return -1;
          }else{
            return this->vet[posicao];
          }
    }
    void Vetor::imprimir(){
         cout << "[";
        for (int i=0; i < this->qtd; i++){
            cout << this->vet[i];
              if (i < this->qtd - 1) cout << ",";
         }
          cout << "]" << endl;
     }
     string Vetor::toString(){
     string final = "[";
        for(int i = 0; i < this->qtd; i++){
            final += to_string(this->vet[i]);
             if(i < this->qtd-1)final += ',';
        }
        final += "]";
        return final;
     }