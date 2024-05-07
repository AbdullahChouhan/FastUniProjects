#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long long int fac(unsigned int n) {
    if (n > 0)
        return (n * fac(n - 1));
    else
        return 1;
}

int main()
{
    int flip = 0, j;
    float result, x;
    cout << "Enter value to calculate f(x) of: ";
    cin >> x;
    result = x;
    cout << "Enter number of terms to calculate to: ";
    cin >> j;
    if (j < 1) {
        cout << "Invalid value entered, taking 20 instead";
        j = 20;
    }
    if (j == 1)
        cout << x;
    else {
        for (int i = 3; i <= ((j * 2) - 1); i = i + 2)
        {
            if (flip == 0) {
                result = result - (pow(x, i)/fac(i));
                flip = 1;
            }
            else if (flip == 1) {
                result = result + (pow(x, i)/fac(i));
                flip = 0;
            }
        }
    }
    cout << "The answer is " << fixed << setprecision(5) << result << endl;
    
    return 0;
}