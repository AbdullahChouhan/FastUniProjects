#include <iostream>
using namespace std;

int main()
{
    int n, even = 0;
    cout << "Enter number: ";
    cin >> n;
    if (n < 0) {
        cout << "Invalid value entered, setting as 5";
        n = 5;
    }
    if (n % 2 == 0) {
        even = 1;
        n++;
    }
    for (int i = 1; i < n; i++)
    {
        for (int space = 0; space < i - 1; space++)
            cout << " ";
        cout << i;
        for (int space = 2 * (n - i) - 1 - even; space > 0; space--)
            cout << " ";
        cout << i;
        cout << "\n";
    }
    if (!even)
    {
        for (int space = 0; space < n - 1; space++)
            cout << " ";
        cout << n << "\n";
    }
    
    for (int i = n - 1; i >= 1; i--)
    {
        for (int space = 0; space < i - 1; space++)
            cout << " ";
        cout << i;
        for (int space = 2 * (n - i) - 1 - even; space > 0; space--)
            cout << " ";
        cout << i;
        cout << "\n";
    }
}