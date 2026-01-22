#include<iostream>

int main(){
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = n - 1 - i; j > 0; j--){
            std::cout << " ";
        }

        for(int j = 0; j < 2 * i + 1; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= i ; j++){
            std::cout << " ";
        }

        for(int j = 0; j < 2 * (n - i) - 3; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}