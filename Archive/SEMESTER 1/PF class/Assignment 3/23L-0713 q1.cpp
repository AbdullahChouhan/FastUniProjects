#include <iostream>
#include <conio.h>
using namespace std;

int diceroll()
{
    srand(time(0));
    return 1 + rand() % 6;
}

int main()
{
    int roll, ptot[2] = {0, 0}, player = 1;
    cout << "Press any key to roll the dice\n";
    getch();
    while (ptot[player] != 20)
    {
        player = !player;
        roll = diceroll();

        cout << "Player " << player + 1 << "'s turn: " << roll << "\n";
        if (ptot[player] + roll > 20)
            cout << "Player " << player + 1 << "'s total: " << ptot[player] << " (move not possible)\n";
        else
        {
            ptot[player] += roll;
            cout << "Player " << player + 1 << "'s total: " << ptot[player] << "\n";
        }

        if (ptot[player] != 20)
        {
            getch();
        }
    }
    cout << "Player " << player + 1 << " Won!";
    return 0;
}