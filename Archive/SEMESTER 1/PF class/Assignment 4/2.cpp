/*
//First Program
#include <iostream>
using namespace std;

int main()
{
    int x, y, z, largest;
    cout << "Enter three numbers\n";
    cin >> x >> y >> z;
    if (y >= x) 
    {
        if (y >= z)
            largest = y;
        else
            largest = z;
    }
    else
    {
        if (x >= z)
            largest = x;
        else
            largest = z;
    }
    cout << "The largest number is " << largest;
    return 0;
}
*/

/*
//Second Program
#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter a number to calculate sum of all digits: ";
    cin >> n;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    cout << "The sum of all the digits: " << sum << "\n";
    return 0;
}
*/

/*
//Third Program
#include <iostream>
using namespace std;

int main()
{
    int year, leap = 0;
    cout << "Enter a year to check if leap: ";
    cin >> year;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                leap = 1;
        }
        else
            leap = 1;
    }
    if (leap == 1)
        cout << "Leap!";
    else
        cout << "Not leap!";
    return 0;
}
*/

/*
//Fourth Program
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber() {
    srand(time(0));
    return 1 + rand() % 20;
}

int main ()
{
    int random_number = generateRandomNumber();
    int guess;
    while (guess != random_number)
    {
        cout << "Guess a number between 1 and 20: ";
        cin >> guess;
        if (guess > random_number)
            cout << "Too high. Try again.\n";
        else if (guess < random_number)
            cout << "Too low. Try again.\n";    
    }
    cout << "Success!";
    return 0;
}
*/

/*
//Fifth Program
#include <iostream>
using namespace std;

int main()
{
    int n, div = 0;
    cout << "Enter a number to check if prime: ";
    cin >> n;
    if (n > 2) {
        for (int i = 2; i <= (n - 1); i++)
        {
            if (n % i == 0)
                div = 1;
        }
    }
    else if ( n == 2)
        div = 1;
    if (!div)
        cout << "Prime!";
    else
        cout << "Not Prime!";
    return 0;
}
*/

/*
//Sixth Program
#include <iostream>
using namespace std;

int main()
{
    int n, temp, first = 0, second = 1;
    cout << "Enter a number to generate terms of the Fibonacci sequence of: ";
    cin >> n;
    if (n > 0) {
        cout << "0";
        if (n > 1) {
            cout << ", 1";
            if (n > 2) {
                for (int i = 3; i <= n; i++)
                {
                    temp = first;
                    first = second;
                    second += temp;
                    cout << ", " << second; 
                }
            }
        }
    }
    else if (n != 0)
        cout << "Invalid number entered";
    return 0;
}
*/

/*
//Seventh Program
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, orig_n, digits = 0, sum = 0;
    cout << "Enter number to check if Armstrong: ";
    cin >> n;
    orig_n = n;
    while (n != 0) {
        digits++;
        n /= 10;
    }
    n = orig_n;
    while (n != 0) {
        sum += pow(n % 10, digits);
        n /= 10;
    }
    if (sum == orig_n)
        cout << "Armstrong!";
    else
        cout << "Not Armstrong!";
    return 0;
}
*/

/*
//Eighth Program
#include <iostream>
using namespace std;

int main()
{
    int n, orig_n, reverse = 0;
    cout << "Enter number to check if palindrome: ";
    cin >> n;
    orig_n = n;
    while (n != 0) {
        reverse = 10 * reverse + (n % 10);
        n /= 10; 
    }
    if (reverse == orig_n)
        cout << "Palindrome!";
    else
        cout << "Not Palindrome";
    return 0;
}
*/