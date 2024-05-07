#include <iostream>

class Point{
    private:
        int x, y;
    public:
        Point(int x, int y){
            this->x = x;
            this->y = y;
            std::cout << "Point() called\n";
        }
        void print() {
            std::cout << "(" << x << ", " << y << ")\n";
        }
        ~Point() {
            std::cout << "~Point() called\n";
        }
};