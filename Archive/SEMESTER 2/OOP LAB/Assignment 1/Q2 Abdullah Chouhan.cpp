#include <iostream>
using namespace std;

int main() {
    int arr[10], n = 10, search, i, NoMore, temp;
    cout << "Enter array values\n";
    for (i = 0; i < 10; i++)
        cin >> arr[i];
    cout << "Sorting array...\n";
    
    do
    {
        NoMore = 1;
        for (i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                NoMore = 0;
            }
        }
        n--;
    } while (NoMore != 1);
    cout << "Enter value to search for...";
    cin >> search;

    int first = 0, found = 0, mid;
    n = 9;
    NoMore = 0;
    while (!NoMore && !found)
    {
        mid = (first + n) / 2;
        if (arr[mid] == search)
            found = 1;
        else
        {
            if (first >= n) 
                NoMore = 1;
            else
            {
                if (arr[mid] > search)
                    n = mid - 1;
                else
                    first = mid + 1;
            }
        }
    }

    if (found)
        cout << "Value " << search << " found at index " << mid;
    else
        cout << "Value not found!";
}