#include <iostream>
using namespace std;

int main()
{
    int sand = 10;
    char c = 'X';
    while (sand >= 0) {
        cout << "00000000000\n";
        for (int i = 5; i >= 1; i--)
        {
            for (int j = 5; j > i; j--)
                cout << " ";

            if (sand >= 6)
                c = 'X';
            else
                c = ' ';

            cout << "0";
            for (int j = 2 * i - 1; j >= 1; j--)
            {
                cout << c;
            }
            cout << "0\n";
        }
        cout << "     0\n";
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 5; j > i; j--)
                cout << " ";
            cout << "0";
            for (int j = 2 * i - 1; j >= 1; j--)
            {
                cout << " ";
            }
            cout << "0\n";
        }
        cout << "00000000000\n";
        sand--;
    }
}


//Stack - Leap - Global/Static - Text/Code