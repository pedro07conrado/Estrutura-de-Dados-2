#include <iostream>
using namespace std;
int a = 10;
int b = 2;

void imprimir_binario(int a){
    if(a == 0)
        return;
    imprimir_binario(a/2);
    cout << a%2;
}

int main(){
   // cout << mult(a, b) <<endl;
   imprimir_binario(1); 
    cout << endl;
    return 0;
}