/*
//Program 1:

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int AGE;
    string NAME, CITY, COLLEGE, PROFESSION, ANIMAL, PETNAME;
    cout << "Enter your name: ";
    cin >> NAME;
    cout << "Enter your age: ";
    cin >> AGE;
    cout << "Name a city: ";
    cin >> CITY;
    cout << "Name a college: ";
    cin >> COLLEGE;
    cout << "Name a profession: ";
    cin >> PROFESSION;
    cout << "Name a type of animal: ";
    cin >> ANIMAL;
    cout << "Name a pet's name: ";
    cin >> PETNAME;
    cout << "There once was a person named " << NAME << " who lived in " << CITY << ". At the age of " << AGE << ", " << NAME << " went to college at " << COLLEGE << ". " << NAME << " graduated and went to work as a " << PROFESSION << ". Then, " << NAME << " adopted ";
    if (ANIMAL[0] == 'A' || ANIMAL[0] == 'E' || ANIMAL[0] == 'I' || ANIMAL[0] == 'O' || ANIMAL[0] == 'U' || ANIMAL[0] == 'a' || ANIMAL[0] == 'e' || ANIMAL[0] == 'i' || ANIMAL[0] == 'o' || ANIMAL[0] == 'u')
        cout << "an ";
    else
        cout << "a ";
    cout << ANIMAL << " named " << PETNAME << ". They both lived happily ever after!";
    return 0;
}
*/

/*
//Program 2:
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
*/

/*
//Program 3:
#include <iostream>
using namespace std;

int main()
{
    const double Discount10Rooms = 0.1, Discount20Rooms = 0.2, Discount30Rooms = 0.3, Discount3Days = 0.05;
    double RoomCost, SalesTax, TDiscount, TCost;
    int DurationDays, NumRoomsBooked;

    cout << "Enter the cost of renting one room: $";
    cin >> RoomCost;
    cout << "Enter number of rooms booked: ";
    cin >> NumRoomsBooked;
    cout << "Enter duration of stay in days: ";
    cin >> DurationDays;
    cout << "Enter sales tax (as a percent): ";
    cin >> SalesTax;

    if (NumRoomsBooked >= 10)
        TDiscount = Discount10Rooms;
    else if (NumRoomsBooked >= 20)
        TDiscount = Discount20Rooms;
    else
        TDiscount = Discount30Rooms;
    if (DurationDays >= 3)
        TDiscount += Discount3Days;
    TCost = RoomCost * NumRoomsBooked * DurationDays * (1.00 - TDiscount);
    cout << "The cost of renting one room: $" << RoomCost << "\n";
    cout << "The discount on each room: " << TDiscount * 100 << "%\n";
    cout << "The number of rooms booked: " << NumRoomsBooked << "\n";
    cout << "The number of days rooms booked for: " << DurationDays << "\n";
    cout << "The total cost of the rooms: $" << TCost << "\n";
    cout << "The sales tax: " << SalesTax << "%\n";
    cout << "The total billing amount: $" << TCost * (1.00 + (SalesTax / 100.00));
    return 0;
}
*/

/*
//Program 4, Task 1:
#include <iostream>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, m12, m23;

    cout << "Enter first point's coordinates\n";
    cin >> x1 >> y1;
    cout << "Enter second point's coordinates\n";
    cin >> x2 >> y2;
    cout << "Enter third point's coordinates\n";
    cin >> x3 >> y3;

    m12 = (y2 - y1) / (x2 - x1);
    m23 - (y3 -y2) / (x3 - x2);

    if (m12 == m23)
        cout << "The points are collinear!";
    else 
        cout << "The points are not collinear!";
    return 0;
}
*/

/*
//Program 4, Task 2
#include <iostream>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter first point's coordinates\n";
    cin >> x1 >> y1;
    cout << "Enter second point's coordinates\n";
    cin >> x2 >> y2;
    cout << "Enter third point's coordinates\n";
    cin >> x3 >> y3;

    if ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0)
        cout << "The points are collinear!";
    else 
        cout << "The points are not collinear!";
    return 0;
}
*/

/*
//Program 5:
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
*/