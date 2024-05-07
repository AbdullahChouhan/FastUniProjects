#include <iostream>
using namespace std;

int main() 
{
    int arr[5] = {50,23,6,8,10}, n = 4, NoMoreSwaps;
    do
    {
        NoMoreSwaps = 1;
        for (int i = 0; i <= n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                NoMoreSwaps = 0;
            }
        }
        n--;
    } while (NoMoreSwaps != 1);
}