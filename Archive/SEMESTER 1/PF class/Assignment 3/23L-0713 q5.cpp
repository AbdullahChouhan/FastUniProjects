#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * (factorial(n - 1));
}
int nPr(int n, int r)
{
    return factorial(n)/factorial(n-r);
}
int nCr(int n, int r)
{
    return factorial(n)/factorial(n-r)*factorial(r);
}
int nCr2(int n, int r)
{
    return nPr(n ,r)/factorial(r);
}
int main()
{
    int choice, n, r;
    cout << "Menu:-\n";
    cout << "Enter 1 to print factorial of number\n";
    cout << "Enter 2 to print nPr\n";
    cout << "Enter 3 to print nCr\n";
    cout << "Enter 4 to print nCr type 2\n";
    cout << "Enter 5 to Exit Program\n";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter number: ";
        cin >> n;
    }
    if (choice > 1 && choice < 5)
    {
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter r: ";
        cin >> r;
    }

    switch (choice)
    {
    case 1:
        cout << factorial(n);
        break;
    case 2:
        cout << nPr(n, r);
        break;
    case 3:
        cout << nCr(n, r);
        break;
    case 4:
        cout << nCr2(n, r);
        break;
    case 5:
        break;
    default:
        break;
    }
}