#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum;
    int *xPtr, *yPtr, *sumPtr;

    num1 = 5, num2 = 7, sum = 0, xPtr = 0, yPtr = 0, sumPtr = 0;
    cout << "Num1 = " << num1 << '\n';
    cout << "Num2 = " << num2 << '\n';
    cout << "Address of Num1 = " << &num1 << '\n';
    cout << "Address of Num2 = " << &num2 << '\n';
    xPtr = &num1, yPtr = &num2;
    cout << "*xPtr = " << *xPtr << '\n';
    cout << "*yPtr = " << *yPtr << '\n';
    sumPtr = &sum;
    sum = *xPtr + *yPtr;
    cout << "*sumPtr = " << *sumPtr << '\n';
    cout << "xPtr = " << xPtr << '\n';
    cout << "yPtr = " << yPtr;
}