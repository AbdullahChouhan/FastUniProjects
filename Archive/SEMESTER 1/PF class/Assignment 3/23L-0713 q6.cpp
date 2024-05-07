#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num, sum2 = 0, temp;
    cin >> num;
    int sum1 = num % 10;
    for (int i = 2; i < 8; i+=2)
    {
        sum1 += int(num / pow(10,i)) % 10;
    }
    for (int i = 1; i < 8; i+=2)
    {
        temp = int(num / pow(10,i)) % 10;
        temp*=2;
        sum2+= temp % 10;
        temp/=10;
        sum2+= temp % 10;
    }
    if ((sum1 + sum2) % 10 == 0)
        cout << "Valid";
}