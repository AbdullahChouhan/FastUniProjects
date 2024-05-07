#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[10];
    cin.getline(c,10); // for char arrays
    cout << c;
    string k;
    getline(cin,k); // for strings
    cout << k;
}