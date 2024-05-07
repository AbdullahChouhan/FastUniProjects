#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int num[10], temp, i, large2;
    cout << "Inserting 10 random values to fill array\n";
    num[1] = (rand() % 20) + 1;
    int sum = num[1], largest = num[1], largeid = 1;
    for (i = 2; i <= 10; i++)
    {
        num[i] = (rand() % 20) + 1;
        sum += num[i];
        if (num[i] > largest) {
            largeid = i;
            large2 = largest;
            largest = num[i];
        }
    }
    cout << "Outputting in reverse\n";
    for (i = 10; i >= 1; i--)
    {
        cout << num[i] << '\n';
    }

    cout << "Reversing...\n";
    for (i = 10; i >= 6; i--)
    {
        temp = num[11 - i];
        num[11 - i] = num[i];
        num[i] = temp;
    }

    cout << "Outputting...\n";
    for (i = 1; i <= 10; i++)
    {
        cout << num[i] << '\n';
    }
    
    cout << "The sum is " << sum << '\n';
    cout << "The largest is " << largest << " at index " << largeid;
    return 0;
 
    //The process Ma'am is describing only needs to be done for an array with preset values
    //Implementing on user values is... INEFFICIENT
    //Shame on us
}