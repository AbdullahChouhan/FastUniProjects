#include <iostream>
using namespace std;

int main()
{
    int m, d, arr[10] = {1, 2, 1, 3, 2, 2, 3, 1, 5, 2}, count = 0, sum, ReachedEnd;
    cout << "Enter month, between 1 and 10";
    cin >> m;
    m--;
    while (m > 9 || m < 0)
    {
        cout << "Invalid value entered, try again";
        cin >> m;
        m--;
    }
    cout << "Enter day, between 1 and 31";
    cin >> d;
    d--;
    while (m > 30 || m < 0)
    {
        cout << "Invalid value entered, try again";
        cin >> d;
        d--;
    }
    cin >> d;
    for (int i = 0; i < 10 && (i + m) <= 10; i+=m)
    {
        for (int j = i; i <= (j + m); j++)
            sum+=arr[j];
        if (sum == d)
        {
            count++;
            sum = 0;
        }
    }
    int i, j;
    do
    {
        ReachedEnd = 1;
    } while (ReachedEnd != 1);
    cout << count;
}