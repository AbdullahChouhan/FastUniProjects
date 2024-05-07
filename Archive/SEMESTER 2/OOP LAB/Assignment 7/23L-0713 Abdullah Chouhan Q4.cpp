#include <iostream>

class Matrix {
    private:
        int** matrix;
        int rows;
        int cols;
    public:
        Matrix(int rows = 0, int cols = 0) {
            this->rows = rows;
            this->cols = cols;
            matrix = new int* [rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        friend std::ostream& operator<<(std::ostream& cout, const Matrix& m) {
            for (int i = 0; i < m.rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    cout << m.matrix[i][j] << " ";
                }
                cout << std::endl;
            }
            return cout;
        }
        friend std::istream& operator>>(std::istream& cin, Matrix& m) {
            std::cout << "Enter matrix elements: " << std::endl;
            for (int i = 0; i < m.rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    cin >> m.matrix[i][j];
                }
            }
            return cin;
        }
        Matrix operator* (const Matrix& other) {
            if (this->cols != other.rows) {
                throw std::invalid_argument("Columns of 1st matrix must equal rows of 2nd matrix");
            }
            Matrix result(this->rows, other.cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < other.cols; j++) {
                    for (int k = 0; k < this->cols; k++) {
                        result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                    }
                }
            }
            return result;
        }
        ~Matrix() {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
        }
};

int main() {
    int rows, cols;
    std::cout << "Enter rows and columns for first matrix: ";
    std::cin >> rows >> cols;
    Matrix m1(rows, cols);
    std::cout << "Enter rows and columns for second matrix: ";
    std::cin >> rows >> cols;
    Matrix m2(rows, cols);
    std::cout << "Enter first matrix: ";
    std::cin >> m1;
    std::cout << "Enter second matrix: ";
    std::cin >> m2;
    Matrix m3;
    m3 = m1 * m2;
    std::cout << "Product of matrices: ";
    std::cout << m3;
    return 0;
}