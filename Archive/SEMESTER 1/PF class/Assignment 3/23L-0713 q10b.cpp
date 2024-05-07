#include <iostream>
using namespace std;

int func_first(int i) {
    for (int first = 1; first <= i; first++)
    {
        cout << "*";
    }
    return 0;
}

int main()
{
    int rows;
    cout << "Please enter the number of rows: ";
    cin >> rows;
    if (rows < 0) {
        cout << "Invalid valuse entered, setting rows to 12";
        rows = 12;
    }
    int spaces = rows * 2;
    for (int i = 1; i <= rows; i++, spaces-= 2)
    {
        func_first(i);
        for (int space = spaces; space > 2; space--)
        {
            cout << " ";
        }
        func_first(i);
        cout << "\n";
    }
    for (int i = rows; i >= 1; i--, spaces+= 2)
    {
        func_first(i);
        for (int space = 0; space < spaces; space++)
        {
            cout << " ";
        }
        func_first(i);
        cout << "\n";
    }
    return 0;
}