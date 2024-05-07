#include <iostream>

const double pi = 3.1415926535897932384626433832795;

class Circle {
    private:
        int radius;
        float area;
    
    public:
        Circle(int r) : radius(r) {}

        float CalculateArea() {
            return area = pi * radius * radius;
        }
};

int main() {
    Circle circle(5);
    std::cout << circle.CalculateArea();
    return 0;
}