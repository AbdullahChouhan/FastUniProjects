#include <iostream>

class ComplexNumber {
    private:
        double real;
        double imaginary;
    public:
        ComplexNumber(double real = 0, double imaginary = 0) {
            this->real = real;
            this->imaginary = imaginary;
        }
        void display() {
            std::cout << real << " + " << imaginary << "i\n";
        }
        ComplexNumber operator+(const ComplexNumber& other) {
            return ComplexNumber(this->real + other.real, this->imaginary + other.imaginary);
        }
        ComplexNumber operator-(const ComplexNumber& other) {
            return ComplexNumber(this->real - other.real, this->imaginary - other.imaginary);
        }
        ComplexNumber operator*(const ComplexNumber& other) {
            return ComplexNumber(this->real * other.real - this->imaginary * other.imaginary, this->real * other.imaginary + this->imaginary * other.real);
        }
        friend std::ostream& operator<<(std::ostream& cout, const ComplexNumber& cn) {
            cout << cn.real << " + " << cn.imaginary << "i";
            return cout;
        }
        friend std::istream& operator>>(std::istream& cin, ComplexNumber& cn) {
            std::cout << "Enter real part: ";
            cin >> cn.real;
            std::cout << "Enter imaginary part: ";
            cin >> cn.imaginary;
            return cin;
        }
};

int main() {
    ComplexNumber c1, c2, c3;
    std::cin >> c1 >> c2;
    c3 = c1 + c2;
    std::cout << "C1 = " << c1 << "\nC2 = " << c2 << "\nSum = " << c3;
    c3 = c1 - c2;
    std::cout << "\nC1 = " << c1 << "\nC2 = " << c2 << "\nDifference = " << c3;
    c3 = c1 * c2;
    std::cout << "\nC1 = " << c1 << "\nC2 = " << c2 << "\nProduct = " << c3;
    return 0;
}