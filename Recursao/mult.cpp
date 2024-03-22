#include <iostream>

using namespace std; 

int mult(int a, int b) {
    if(a == 1)
        return b;

    if(a == 0 || b == 0)
        return 0;

    return  mult(a-1, b) + b;
}

int main(){
    int a = 1000;
    int b = 5;
    cout << mult(a, b) << endl;
    return 0;
}