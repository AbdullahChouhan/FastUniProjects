#include <iostream>

class Shape {
    public:
        virtual void area() {
            std::cout << "Shape\n";
        }
};

class Circle : public Shape {
    private:
        int radius;
    public:
        Circle(int radius) : radius(radius) {

        }
        void area() override {
            std::cout << "Circle: " << 3.14 * radius * radius << '\n';
        }
};
class Rectangle : public Shape {
    private:
        int length;
        int breadth;
    public:
        Rectangle(int length, int breadth) : length(length), breadth(breadth) {
            
        }
        void area() override {
            std::cout << "Rectangle: " << length * breadth << '\n';
        }
};

void areaSize(Shape** shape, int size) {
    for (int i = 0; i < size; i++) {
        shape[i]->area();
    }
}

int main () {
    Shape** shapes = new Shape*[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(5, 10);
    areaSize(shapes, 2);
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
    delete[] shapes;
    return 0;
}