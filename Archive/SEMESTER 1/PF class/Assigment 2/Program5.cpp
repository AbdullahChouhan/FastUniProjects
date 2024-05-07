#include <iostream>
using namespace std;

int main()
{
    int AmountDue, CustomerReciept, money, dol, qua, dim, nic;
    cout << "Enter amount due (in pennies): ";
    cin >> AmountDue;
    cout << "Enter the customer's reciept (in pennies): ";
    cin >> CustomerReciept;
    money = CustomerReciept - AmountDue;
    if (money >= 0) {
        dol = money / 100;
        money %= 100;
        qua = money / 25;
        money %= 25;
        dim = money / 10;
        money %= 10;
        nic = money / 5;
        money %= 5;
        cout << "The customer should recieve " << dol << " dollars, " << qua << " quarters, " << dim << " dimes, " << nic << " nickels, and " << money << " pennies";
    }
    else
        cout << "The customer has paid an inefficient amount";
    return 0;
}