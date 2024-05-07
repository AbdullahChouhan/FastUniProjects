#include <iostream>
using namespace std;

int main()
{
    int n, odd = 0;
    char c;
    cout << "Enter number: ";
    cin >> n;
    cout << "Enter character to print: ";
    cin >> c;
    if (n < 0) {
        cout << "Invalid value entered, setting as 12";
        n = 12;
    }
        
    if (n % 2 == 1) {
        odd = 1;
        n++;
    }
    for (int i = n; i > 0; i -= 2)
    {
        for (int j = n / 2; j > i / 2; j--)
            cout << c;
        cout << " ";
        for (int k = i - 1; k > 0; k--)
            cout << c;
        if (i != 0)
            cout << " ";
        for (int j = n / 2; j > i / 2; j--)
            cout << c;
        cout << "\n";
    }
    
    for (int i = 0; i <= n; i += 2)
    {   
        if (odd == 0)
        {
            for (int j = n / 2; j > i / 2; j--)
            cout << c;
        cout << " ";
        for (int k = i - 1; k > 0; k--)
            cout << c;
        if (i != 0)
            cout << " ";
        for (int j = n / 2; j > i / 2; j--)
            cout << c;
        cout << "\n";
        }
        else
            odd = 0;
    }
    return 0;
}