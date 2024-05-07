#include <iostream>
using namespace std;

int main()
{
    int n, range, sum;
    cout << "Enter the sum: ";
    cin >> sum;
    cout << "Enter a range to pairs of numbers that equal the sum\n";
    cout << "Lower Bound: ";
    cin >> n;
    cout << "Upper Bound: ";
    cin >> range;
    if (n > range) {
        cout << "Lower bound cannot be more than upper bound, switching bounds...\n";
        n += range;
        range = n - range;
        n -= range;
    }
    for (; n <= range; n++)
    {
        if (n != 0)
        {
            for (int i = n; i <= range; i++)
            {
                if (n + i == sum)
                    cout << n << " + " << i << "\n";
            }
        }
    }
}