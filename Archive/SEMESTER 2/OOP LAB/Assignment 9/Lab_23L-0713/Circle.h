#include <Point.h>
#include <iostream>

class Circle {
    private:
        Point center;
        int radius;
    public:
        Circle(int x, int y, int r) : center(x, y), radius(r) {
            std::cout << "Circle() called\n";
        }
        void print() {
            std::cout << "Circle: ";
            center.print();
            std::cout << ", " << radius << '\n';
        }
};