#include <iostream>
using namespace std;

int main()
{
    int first = 1, second = 2, third = 3, current, sum = 6, j;
    cout << "Enter terms to calculate sum up to: ";
    cin >> j;
    if (j < 1) {
        cout << "Invalid value entered, taking 50";
        j = 50;
    }
    else if (j < 4) 
        cout << j;
    else {
        for (int i = 4; i <= j; i++)
        {
            current = first + third;
            sum = sum + current;
            first = second;
            second = third;
            third = current;
        }
        cout << "The sum is: " << sum;
    }
    return 0;
}
