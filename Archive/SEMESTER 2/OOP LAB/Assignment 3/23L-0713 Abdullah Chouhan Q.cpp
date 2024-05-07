#include <iostream>
using namespace std;

int* InputArray (int& size) {
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter values...\n";
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> *(arr + i);
    return arr;
}

void OutputArray(int* arr, const int& size) {
    cout << "Outputting...\n";
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << "\n";
}

int* ExpandDoubleOutputArray(int& size, int& start) {
    int input = 0;
    size = 5; start = 0;
    int* arr = new int[size];
    int* arr2 = nullptr;
    cout << "Enter values for the array, -1 to stop\n";
    do
    {
        for (start; start < size; start++)
        {
            cin >> input;
            if (input != -1)
                *(arr + start) = input;
            else
                break;
        }
        if (input == -1)
            break;
        size *= 2;
        arr2 = new int[size];
        for (int i = 0; i < size / 2; i++)
            *(arr2 + i) = *(arr + i);
        delete[] arr;
        arr = arr2;
    } while (1);
    cout << "Outputting in reverse...\n";
    for (int i = start - 1; i > -1; i--) {
        cout << *(arr + i) << "\n";
    }
    return arr;
}

int SumArray(int* arr, int& start) {
    int sum = 0;
    for (int i = start - 2; i > -1; i--)
        sum += *(arr + i);
    return sum;
}

int main() {
    int size, start;
    int* arr = InputArray(size);
    OutputArray(arr, size);
    delete[] arr;
    arr = ExpandDoubleOutputArray(size, start);
    cout << "Sum of array elements: " << SumArray(arr, size);
    delete[] arr;
    return 0;
}