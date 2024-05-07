#include <iostream>
using namespace std;

int main()
{
    double buyprice, sellprice, commission;
    buyprice = 1000 * 45.50;
    cout << "Joe bought the stocks for $" << buyprice << "\n";
    commission = buyprice * 0.02;
    cout << "Joe paid a commission of $" << commission << " for his purchase\n";
    buyprice += commission;
    sellprice = 1000 * 56.90;
    cout << "Joe sold the stocks for $" << sellprice << "\n";
    commission = sellprice * 0.02;
    cout << "Joe paid a commission of $" << commission << " for his sale\n";
    sellprice += commission;
    cout << "Joe made a profit of $" << sellprice - buyprice;
    return 0;
}