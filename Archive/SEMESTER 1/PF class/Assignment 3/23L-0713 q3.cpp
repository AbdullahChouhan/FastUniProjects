#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter height of the upper portion of the kite: ";
    cin >> n;
    if (n < 2) {
        cout << "Invalid value entered, setting as 5";
        n = 5;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n * 2 - 2; j >= i * 2 + 1; j--)
            cout << " ";
        cout << "*";
        for (int j = 1; j <= i * 2 - 1; j++)
            cout << " ";
        if (i)
            cout << "|";
        for (int j = 1; j <= i * 2 - 1; j++)
            cout << " ";
        if (i)
            cout << "*";
        cout << "\n";
    }
    cout << "*";
    for (int j = 1; j <= n * 2 - 3; j++)
        cout << "-";
    cout << "|";
    for (int j = 1; j <= n * 2 - 3; j++)
        cout << "-";
    cout << "*\n";
    for (int i = n * 2 - 2; i > 1; i--)
    {
        for (int j = 1; j < n * 2 - i; j++)
            cout << " ";
        cout << "*";
        for (int j = i - 2; j >= 1; j--)
            cout << " ";
        if (i)
            cout << "|";
        for (int j = i - 2; j >= 1; j--)
            cout << " ";
        if (i)
            cout << "*";
        cout << "\n";
    }
    for (int j = 1; j < n * 2 - 1; j++)
            cout << " ";
    cout << "*";
}