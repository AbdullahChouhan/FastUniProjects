/*
//Program 1: 
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int i = 0; i < 25; i++)
    {
        cout << (i*2 + 1) << " : " << sqrt((i * 2) + 1) << "\n";
    }
    return 0;
}
*/

/*
//Program 2:
#include <iostream>
using namespace std;

long long int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * (factorial(n - 1));
}

int main()
{
    int num = 0;
    cout << "Enter any number to calculate factorial, 0 to stop";
    cin >> num;
    while (num != 0)
    {
        cout << factorial(num) << "\n";
        cout << "Enter any number to calculate factorial, 0 to stop";
        cin >> num;
    }
    return 0;
}
*/

/*
//Program 3: 
#include <iostream>
using namespace std;

int main()
{
    int base, exponent, result = 1;
    cout << "Enter the base number: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    cout << "The result is: ";
    do
    {
        result *= base;
        exponent--;
    } while (exponent > 0);
    cout << result;
    return 0;
}
*/

/*
//Program 4: 
#include <iostream>
using namespace std;

int main()
{
    int num, length;
    cout << "Enter the table number: ";
    cin >> num;
    cout << "Enter the length of the table: ";
    cin >> length;
    if (length > 1) {
        for (int i = 1; i <= length; i++)
            cout << num << " x " << i << " = " << num * i << "\n";
    }
    else {
        for (int i = 1; i >= length; i--)
            cout << num << " x " << i << " = " << num * i << "\n";
    }
    return 0;   
}
*/

/*
//Program 5:
#include <iostream>
using namespace std;

int main()
{
    int floors, rooms = 0, occ = 0, input;
    cout << "How many floors does the hotel have: ";
    cin >> floors;
    for (int i = 1; i <= floors; i++)
    {
        cout << "How many rooms does floor " << i << " have: ";
        cin >> input;
        rooms += input;
        cout << "How many of them are unoccupied: ";
        cin >> input;
        occ += occ;
    }
    cout << "Total number of rooms is " << rooms;
    cout << "Total number of occupied rooms is " << occ;
    cout << "Total number of unoccupied rooms is " << rooms - occ;
    cout << "Total number of percentage occupied rooms is " << occ / rooms;
}
*/

/*
//Program 6:
#include <iostream>
using namespace std;

int main()
{
    int n, range;
    cout << "Enter the starting point: ";
    cin >> n;
    cout << "Enter the ending point: ";
    cin >> range;
    if (n > range) {
        cout << "Lower bound cannot be more than upper bound, switching bounds...\n";
        n += range;
        range = n - range;
        n -= range;
    }
    for (range; range >= n; range--)
    {
        for (int i = n; i <= range; i++)
        {
            cout << range << " ";
        }
        cout << "\n";
    }
}
*/

/*
// Program 7:
#include <iostream>
using namespace std;

int main()
{
    int n, result = 0;
    cout << "Enter a positive integer n: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        result += i * i;
        cout << i << "^2 ";
        if (i < n)
            cout << "+ ";
        else
            cout << "= " << result;
    }
}
*/

/*
//Program 8:
#include <iostream>
using namespace std;

int main()
{
    char c;
    for (int i = 1; i <= 9; i++)
    {
        cout << "=";
        if (i == 1 || i == 9)
            c = '=';
        else
            c = ' ';
        for (int j = 1; j <= 19; j++)
            cout << c;
        cout << "=\n";
    }
}
*/

/*
//Program 9:
#include <iostream>
using namespace std;

int main()
{
    int sum = 0, arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
        cout << arr[i];
        if (i < 9)
            cout << " + ";
        else
            cout << " = " << sum;
    }
}
*/

/*
//Program 10:
#include <iostream>
using namespace std;

int main()
{
    int arr[5], temp;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value for index " << i << " element: ";
        cin >> arr[i];
    }
    cout << "Reversing...\n";
    for (int i = 4; i >= 2; i--)
    {
        temp = arr[4 - i];
        arr[4 - i] = arr[i];
        arr[i] = temp;
    }
    cout << "Outputting...\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << '\n';
    }
}
*/

#include <iostream>
#include <cmath>
using namespace std;

long long int factorial(int n) //Used in program 2
{
    if (n == 0)
        return 1;
    return n * (factorial(n - 1));
}

int main()
{
    int choice, num, sum, base, exponent, result, length, floors, rooms, occ, input, n, range, arr[10] = {1,2,3,4,5,6,7,8,9,10}, arr1[5], temp;;
    char c;
    cout << "Enter program number between 1 to 10, any other to exit: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        for (int i = 0; i < 25; i++)
        {
            cout << (i*2 + 1) << " : " << sqrt((i * 2) + 1) << "\n";
        }
        break;
    case 2:
        num = 0;
        cout << "Enter any number to calculate factorial, 0 to stop";
        cin >> num;
        while (num != 0)
        {
            cout << factorial(num) << "\n";
            cout << "Enter any number to calculate factorial, 0 to stop";
            cin >> num;
        }
        break;
    case 3:
        result = 1;
        cout << "Enter the base number: ";
        cin >> base;
        cout << "Enter the exponent: ";
        cin >> exponent;
        cout << "The result is: ";
        do
        {
            result *= base;
            exponent--;
        } while (exponent > 0);
        cout << result;
        return 0;
        break;
    case 4:
        cout << "Enter the table number: ";
        cin >> num;
        cout << "Enter the length of the table: ";
        cin >> length;
        if (length > 1) {
            for (int i = 1; i <= length; i++)
                cout << num << " x " << i << " = " << num * i << "\n";
        }
        else {
            for (int i = 1; i >= length; i--)
                cout << num << " x " << i << " = " << num * i << "\n";
        }
        return 0; 
        break;
    case 5:
        rooms = 0;
        occ = 0;
        cout << "How many floors does the hotel have: ";
        cin >> floors;
        for (int i = 1; i <= floors; i++)
        {
            cout << "How many rooms does floor " << i << " have: ";
            cin >> input;
            rooms += input;
            cout << "How many of them are unoccupied: ";
            cin >> input;
            occ += occ;
        }
        cout << "Total number of rooms is " << rooms;
        cout << "Total number of occupied rooms is " << occ;
        cout << "Total number of unoccupied rooms is " << rooms - occ;
        cout << "Total number of percentage occupied rooms is " << occ / rooms;
        break;
    case 6:
        cout << "Enter the starting point: ";
        cin >> n;
        cout << "Enter the ending point: ";
        cin >> range;
        if (n > range) {
            cout << "Lower bound cannot be more than upper bound, switching bounds...\n";
            n += range;
            range = n - range;
            n -= range;
        }
        for (range; range >= n; range--)
        {
            for (int i = 1; i <= range; i++)
            {
                cout << range << " ";
            }
            cout << "\n";
        }
        break;
    case 7:
        result = 0;
        cout << "Enter a positive integer n: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            result += i * i;
            cout << i << "^2 ";
            if (i < n)
                cout << "+ ";
            else
                cout << "= " << result;
        }
        break;
    case 8:
        for (int i = 1; i <= 9; i++)
        {
            cout << "=";
            if (i == 1 || i == 9)
                c = '=';
            else
                c = ' ';
            for (int j = 1; j <= 19; j++)
            {
                cout << c;
                if (j == 7 || j == 14)
                {
                    cout << " ";
                }
            }
            cout << "=\n";
        }
        break;
    case 9:
        sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum += arr[i];
            cout << arr[i];
            if (i < 9)
                cout << " + ";
            else
                cout << " = " << sum;
        }
        break;
    case 10:
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter the value for index " << i << " element: ";
            cin >> arr[i];
        }
        cout << "Reversing...\n";
        for (int i = 4; i >= 2; i--)
        {
            temp = arr[4 - i];
            arr[4 - i] = arr[i];
            arr[i] = temp;
        }
        cout << "Outputting...\n";
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << '\n';
        }
        break;
    default:
        break;
    }
}