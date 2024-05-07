#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    if (n < 0) {
        cout << "Invalid value entered, setting as 5";
        n = 5;
    }
    for (int i = 0; i <= n; i++)
    {
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i - 1; j > 0; j--)
        {
            cout << j;
        }
        if (i)
            cout << "*";
        cout << "\n";
    }
    for (int i = n - 1; i >= 1; i--)
    {
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i - 1; j > 0; j--)
        {
            cout << j;
        }
        if (i)
            cout << "*";
        cout << "\n";
    }
    cout << "*";
    return 0;
}