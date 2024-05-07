#include <iostream>

void swapUsingPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReferences(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << '\n';
    swapUsingPointers(&num1, &num2);
    std::cout << "After pointer swapping: num1 = " << num1 << ", num2 = " << num2 << '\n';
    num1 = 10;
    num2 = 20;
    swapUsingReferences(num1, num2);
    std::cout << "After reference swapping: num1 = " << num1 << ", num2 = " << num2 << '\n';
    return 0;
}