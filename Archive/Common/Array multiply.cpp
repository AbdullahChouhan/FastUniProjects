#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

const int MAX_SIZE = 100; // Maximum size for the arrays

// Function to fill a 2D array with random numbers between 1 and 100
void fillArray(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 100 + 1; // Generates a random number between 1 and 100
        }
    }
}

// Function to multiply two 2D arrays and store the result in a third 2D array
void multiplyArrays(const int arr1[MAX_SIZE][MAX_SIZE], const int arr2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}

// Function to display the contents of a 2D array
void displayArray(const int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    int rows, cols;

    // Get the size of the arrays from the user
    cout << "Enter the number of rows for the arrays (1 to " << MAX_SIZE << "): ";
    cin >> rows;

    cout << "Enter the number of columns for the arrays (1 to " << MAX_SIZE << "): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Invalid array size. Exiting program." << endl;
        return 1;
    }

    // Declare 2D arrays
    int array1[MAX_SIZE][MAX_SIZE], array2[MAX_SIZE][MAX_SIZE], resultArray[MAX_SIZE][MAX_SIZE];

    // Fill 2D arrays with random numbers
    fillArray(array1, rows, cols);
    fillArray(array2, rows, cols);

    // Display the original arrays
    cout << "Array 1:" << endl;
    displayArray(array1, rows, cols);

    cout << "Array 2:" << endl;
    displayArray(array2, rows, cols);

    // Multiply arrays and store the result in resultArray
    multiplyArrays(array1, array2, resultArray, rows, cols);

    // Display the result array
    cout << "Result Array:" << endl;
    displayArray(resultArray, rows, cols);

    return 0;
}