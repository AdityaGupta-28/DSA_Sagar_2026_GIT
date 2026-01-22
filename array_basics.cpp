#include<iostream>
using namespace std;

int main(){
    int x = 10;
    cout << "address of x : " << &x << '\n';
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr;
    int *ptr_arr = arr;
    cout << "________\n";
    cout << *ptr_arr;  // 1
    cout << "________\n";
    cout << *(ptr_arr + 1); // 2
    cout << "_________\n";

    cout << *(ptr_arr) + 1; // 2
    int *ptr = &x;
    
    cout << "address of ptr : " << &ptr << '\n';

    cout << "value of/inside ptr : " << ptr << '\n';

    cout << "value at the adress of ptr is " << *ptr;

    int *_arr = new int[5];
    delete[] _arr;
}