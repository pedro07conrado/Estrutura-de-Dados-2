#include "Vetor.cpp"
#include <iostream>

int main(){
   // Vetor v2;
   // v2.anexar(40);
   // v2.anexar(50);
   // v2.anexar(60);
   // v2.anexar(60);
   // v2.anexar(60);
    //v2.anexar(60);
    //v2.imprimir();

     Vetor v1;        //  []
     v1.anexar(10);    // [10]
     v1.anexar(20);    // [10,20]
     v1.anexar(30);    // [10,20,30]
     v1.inserir(5, 0); // [5,10,20,30]
     v1.inserir(15, 2);// [5,10,15,20,30]
     v1.inserir(20, 5);// [5,10,15,20,30,20]
     v1.imprimir();
     v1.substituir(0, 100); // [100,10,15,20,30]
     v1.removerPorElemento(15); // 2  [100,10,20,30]
     v1.imprimir();
     int elementoRemovido;
     v1.removerPorPosicao(0, elementoRemovido);
      cout<<elementoRemovido<<endl;
      string final = v1.toString();
      cout<<final<<endl;
}