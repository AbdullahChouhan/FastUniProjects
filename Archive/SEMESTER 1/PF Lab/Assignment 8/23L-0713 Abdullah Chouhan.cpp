#include <iostream>
using namespace std;

void print5sTable()
{
    for (int i = 1; i <= 10; i++)
        cout << "5 x " << i << " = " << 5 * i << "\n";
}

int series_sum()
{
    int sum_series = 0;
    for (int i = 1; i <= 1000; i++)
        sum_series += i;
    return sum_series;
}

int sumBetween(int start, int end)
{
    int BetweenSum = 0;
    for (int i = start; i <= end; i++)
        BetweenSum += i;
    return BetweenSum;
}

void loop_in_function_and_function_in_loop()
{
    int arr[1000];
    long int LoopSum = 0;
    for (int i = 0; i < 1000; i++)
    {
       arr[i] = sumBetween(2, i + 5);
       LoopSum += arr[i];
    }
    cout << LoopSum / 1000.0;
}

int main()
{
    int choice, sum;
    cout << "Enter program number between 1 to 4, any other to exit: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        print5sTable();
        break;
    case 2:
        sum = series_sum();
        cout << sum;
        break;
    case 3:
        int start, end;
        cout << "Enter start value: ";
        cin >> start;
        cout << "Enter end value: ";
        cin >> end;
        sum = sumBetween(start, end);
        cout << sum;
        break;
    case 4:
        loop_in_function_and_function_in_loop();
        break;
    default:
        break;
    }
}