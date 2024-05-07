#include <iostream>
using namespace std;

int main() {
    int arr[10], search, i;
    cout << "Enter array values\n";
    for (i = 0; i < 10; i++)
        cin >> arr[i];
    cout << "Enter value to search for: ";
    cin >> search;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == search)
            break;
    }

    if (i < 10)
        cout << "Value " << search << " found at index " << i;
    else
        cout << "Value not found!";
}