#include <iostream>

void reverseArray(int *arr, int size) {
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = temp;
    }
}

int main() {
    int size, search;
    std::cout << "Input array size: ";
    std::cin >> size;
    int *ptrarr = new int[size];
    std::cout << "Input " << size << " array values\n";
    for (int i = 0; i < size; i++)
        std::cin >> *(ptrarr + i);
    reverseArray(ptrarr, size);
    std::cout << "Outputting reversed array\n";
    for (int i = 0; i < size; i++)
        std::cout << *(ptrarr + i) << '\n';
    delete[] ptrarr;
    return 0;
}