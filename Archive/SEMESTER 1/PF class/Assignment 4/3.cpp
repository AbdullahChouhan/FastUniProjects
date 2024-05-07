#include <iostream>
using namespace std;

int main()
{
    int n, range, total = 0, div = 0;
    cout << "Enter a range to check primes\n";
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
    for (n; n <= range; n++)
    {
        if (n > 2) {
            for (int i = 2; i < n && div == 0; i++)
            {
                if (n % i == 0)
                    div = 1;
            }
        }
        else if (n == 0 || n == 1)
            div = 1;
        if (!div) {
            cout << n << "\n";
            total++;
        }
        div = 0;
    }
    cout << "The total number of prime numbers in the range given is: " << total;
    return 0;
}