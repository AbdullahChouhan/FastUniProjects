#include <iostream>
#include <fstream>

using namespace std;

void DeleteMatrix(int** matrix, const int rows) {
    if (matrix == nullptr) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** InputMatrix(ifstream& fin, int& rows, int& cols) {
    fin >> rows >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            fin >> *(*(matrix + i) + j);
        }
    }
    return matrix;
}

void OutputMatrix(int** matrix, const int rows, const int cols) {
    if (matrix == nullptr) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << '\n';
    }
}

int** AddMatrix(int** matrixA, int** matrixB, const int rowsA, const int colsA, const int rowsB, const int colsB ) { //Addition error not possible to be preempted without the dimensions of the second matrix
    if (rowsA != rowsB || colsA != colsB) {
        cout << "Addition not possible.\n";
        return nullptr;
    }
    int** matrixOut = new int* [rowsA];
    for (int i = 0; i < rowsA; i++) {
        matrixOut[i] = new int[colsA];
        for (int j = 0; j < colsA; j++) {
            *(*(matrixOut + i) + j) = *(*(matrixA + i) + j) + *(*(matrixB + i) + j);
        }
    }
    return matrixOut;
}

int** TransposeMatrix(int** matrix, const int rows, const int cols) {
    if (matrix == nullptr) {
        return nullptr;
    }
    int** matrixOut = new int* [cols];
    for (int i = 0; i < cols; i++) {
        matrixOut[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            *(*(matrixOut + i) + j) = *(*(matrix + j) + i);
        }
    }
    return matrixOut;
}

bool IsSymmetric(int** matrix, const int rows, const int cols) {
    bool out = true;
    int** matrixT = TransposeMatrix(matrix, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(*(matrixT + i) + j) != *(*(matrix + i) + j)) {
                out = false;
            }
        }
    }
    DeleteMatrix(matrixT, rows);
    return out;
}

void InterchangeRows(int*& row1, int*& row2 ) {
    int* temp = row1;
    row1 = row2;
    row2 = temp;
}

void InterchangeRows(int** matrix) {
    int row1 = 1, row2 = 3;
    InterchangeRows(*(matrix + row1 - 1), *(matrix + row2 - 1));
}

int main() {
    ifstream fin("InputFile.txt");
    if (!fin.is_open()) {
        cout << "Error opening file";
        return 1;
    }
    int rowsA = 0, colsA = 0, rowsB = 0, colsB = 0, rowsC = 0, colsC = 0;
    int** matrixA = InputMatrix(fin, rowsA, colsA);
    int** matrixB = InputMatrix(fin, rowsB, colsB);
    int** matrixC = InputMatrix(fin, rowsC, colsC);
    
    cout << "Matrix A:\n";
    OutputMatrix(matrixA, rowsA, colsA);
    cout << "\nMatrix B:\n";
    OutputMatrix(matrixB, rowsB, colsB);
    cout << "\nMatrix C:\n";
    OutputMatrix(matrixC, rowsC, colsC);

    int** matrixAdded = nullptr;
    cout << "\nA + B:\n";
    OutputMatrix((matrixAdded = AddMatrix(matrixA, matrixB, rowsA, colsA, rowsB, colsB)), rowsA, colsA);
    DeleteMatrix(matrixAdded, rowsA);
    cout << "\nA + C:\n";
    OutputMatrix(matrixAdded = AddMatrix(matrixA, matrixC, rowsA, colsA, rowsC, colsC), rowsA, colsA);
    DeleteMatrix(matrixAdded, rowsA);

    int** matrixT = nullptr;
    cout << "\nTranspose A:\n";
    OutputMatrix(matrixT = TransposeMatrix(matrixA, rowsA, colsA), colsA, rowsA);
    DeleteMatrix(matrixT, colsA);
    cout << "\nTranspose C:\n";
    OutputMatrix(matrixT = TransposeMatrix(matrixC, rowsC, colsC), colsC, rowsC);
    DeleteMatrix(matrixT, colsC);

    cout << "\nMatrix A is ";
    if (!IsSymmetric(matrixA, rowsA, colsA))
        cout << "NOT ";
    cout << "Symmetric\n";
    cout << "\nMatrix B is ";
    if (!IsSymmetric(matrixB, rowsB, colsB))
        cout << "NOT ";
    cout << "Symmetric\n";

    cout << "\nInterchanging Rows of Matrix A: \nrow1: 1\nrow2: 3\n";
    cout << "\nAfter Interchanging Rows Matrix A=\n";
    InterchangeRows(matrixA);
    OutputMatrix(matrixA, rowsA, colsA);

    DeleteMatrix(matrixA, rowsA);
    DeleteMatrix(matrixB, rowsB);
    DeleteMatrix(matrixC, rowsC);

    fin.close();
    return 0;
}