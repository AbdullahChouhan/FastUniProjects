#include <iostream>
using namespace std;

int CheckPrime(int n) {
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int prime1 = 0, prime2 = 0, num;
    bool found = false;
    cout << "Input a positive integer: ";
    cin >> num;
    for (int j = 1; j < num; j++)
    {
        if (CheckPrime(j)) {
            prime1 = j;
            for (int k = prime1; k < num; k++)
            {
                if (CheckPrime(k) && (prime1 + k == num)) 
                {
                    prime2 = k;
                    cout << num << " = " << prime1 << " + " << prime2 << "\n";
                    prime1 = 0;
                    found = true;
                }   
            }
        }
    }
    if (!found)
        cout << num << " cannot be expressed as sum of two prime numbers";
}