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