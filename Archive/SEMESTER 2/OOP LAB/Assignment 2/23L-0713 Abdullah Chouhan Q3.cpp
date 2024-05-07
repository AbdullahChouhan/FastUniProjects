#include <iostream>

int main() {
    int arr[5];
    int* ptrarr = arr;
    int sum = 0;
    std::cout << "Input 5 values for array\n";
    for (int i = 0; i < 5; i++) {
        std::cin >> *(ptrarr + i);
        sum += *(ptrarr + i);
    }
    std::cout << "The sum of the values is " << sum;
    return 0;
}