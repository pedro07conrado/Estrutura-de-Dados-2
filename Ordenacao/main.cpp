#include <iostream>
#include "utils.h" 

int main() {
    // Testar a função de gerar vetor aleatório
    std::vector<int> v = gerar_vetor_aleatorio(10, 42, 100);
    std::cout << "Vetor aleatório:" << std::endl;
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Testar a função de embaralhar
    int arr[] = {1, 2, 3, 4, 5};
    embaralhar(arr, 5, 42);
    std::cout << "Vetor embaralhado:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    

    return 0;
}
