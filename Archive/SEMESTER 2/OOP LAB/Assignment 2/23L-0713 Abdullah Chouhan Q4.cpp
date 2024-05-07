#include <iostream>

int main() {
    int size, search;
    std::cout << "Input array size: ";
    std::cin >> size;
    int *ptrarr = new int[size];
    std::cout << "Input " << size << " array values\n";
    for (int i = 0; i < size; i++)
        std::cin >> *(ptrarr + i);
    std::cout << "Input value to search for: ";
    std::cin >> search;
    for (int i = 0; i < size; i++) {
        if (search == *(ptrarr + i)) {
            std::cout << "Value found at index " << i;
            break;
        }
    }
    delete[] ptrarr;
    return 0;
}