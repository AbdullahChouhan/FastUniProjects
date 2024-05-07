#include <iostream>
using namespace std;

void display(int arr[])
{
    for (int i = 0; i < 10; i++)
        cout << arr[i] << '\n';
}
void reset(int arr[], int arr2[])
{
    for (int i = 0; i < 10; i++)
        arr[i] = arr2[i];
}

int main() {
    int arr[10], arr2[10], n = 10, i, NoMore, temp;
    cout << "Enter array values\n";
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    cout << "\nBubble Sorting array...\n";
    
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
    display(arr);
    reset(arr, arr2);
    
    cout << "\nSelection Sorting array...\n";
    int min, minId, first = 0;
    n = 10;
    do
    {
        min = 9999999;
        NoMore = 1;
        for (i = first; i < n; i++)
        {
            if (arr[i] < min) {
                min = arr[i];
                minId = i;
                NoMore = 0;
            }
        }
        temp = arr[minId];
        arr[minId] = arr[first];
        arr[first] = temp;
        first++;
    } while (NoMore != 1 && first < n);
    display(arr);
    reset(arr, arr2);

    int curr;
    cout << "\nInsertion Sorting array...\n";
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        curr = i - 1;
        while ((arr[curr] > temp) && (curr > -1))
        {
            arr[curr + 1] = arr[curr];
            curr--;
        }
        arr[curr + 1] = temp;
    }
    display(arr);
}