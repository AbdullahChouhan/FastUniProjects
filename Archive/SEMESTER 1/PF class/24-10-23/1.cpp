#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {50,23,6,8,10}, largest = arr[0], Slargest = -999999;
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
        else if (arr[i] > Slargest)
            Slargest = arr[i];
    }
    cout << largest << "\n";
    cout << Slargest;
}