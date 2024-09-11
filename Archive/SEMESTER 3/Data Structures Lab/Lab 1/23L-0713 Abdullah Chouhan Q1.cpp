#include <iostream>

class myVector
{   
    private:
        int capacity, *arrayPtr = nullptr, current = 0;
    public:
        myVector(int n = 2) : capacity(n) {
            if (capacity <= 0) {
                capacity = 2;
            }
            arrayPtr = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                arrayPtr[i] = 0;
            }
        }
        myVector(const myVector &other) : capacity(other.capacity), current(other.current) {
            arrayPtr = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                arrayPtr[i] = other.arrayPtr[i];
            }
        }
        ~myVector() {
            if (arrayPtr != nullptr) {
                delete[] arrayPtr;
            }
        }
        int getCapacity() {
            return capacity;
        }
        int getCurrent() {
            return current;
        }
        void operator+(int value) {
            if (current >= capacity) {
                capacity *= 2;
                int *temp = new int[capacity];
                for (int i = 0; i < current; i++) {
                    temp[i] = arrayPtr[i];
                }
                this->~myVector();
                arrayPtr = temp;
            }
            arrayPtr[++current] = value;
        }
        void operator-() {
            arrayPtr[current--] = 0;
        }
        void operator+(const myVector &other) {
            if (other.current > capacity - current) {
                capacity += capacity - current + other.current;
                capacity *= 2;
                int *temp = new int[capacity];
                for (int i = 0; i < current; i++) {
                    temp[i] = arrayPtr[i];
                }
                this->~myVector();
                arrayPtr = temp;
            }
            for (int i = 0; i < other.current; i++) {
                arrayPtr[++current] = other.arrayPtr[i];
            }
        }
        void operator=(const myVector &other) {
            capacity = other.capacity;
            current = other.current;
            this->~myVector();
            arrayPtr = new int[capacity];
            for (int i = 0; i < capacity; i++) {
                arrayPtr[i] = other.arrayPtr[i];
            }
        }

        int operator[](int index) const {
            if (index >= capacity) {
                throw std::out_of_range("Index out of bounds");
            }
            return arrayPtr[index];
        }
        int& operator[](int index) {
            if (index >= capacity) {
                throw std::out_of_range("Index out of bounds");
            }
            return arrayPtr[index];
        }

        void operator>>(myVector &in) {
            for (int i = 0; i < in.current; i++) {
                operator+(in.arrayPtr[i]);
            }
        }

        friend std::ostream &operator<<(std::ostream &out, const myVector &other) {
            for (int i = 0; i < other.current; i++) {
                out << other.arrayPtr[i] << " ";
            }
            return out;
        }
};

int main() {
    myVector v1(5);
    myVector v2(v1);
    myVector v3(3);
    std::cout << v1.getCapacity() << " " << v1.getCurrent() << "\n";
    std::cout << v2.getCapacity() << " " << v2.getCurrent() << "\n";
    v1 + 5;
    -v1;
    v1 + v2;
    v1 = v2;
    v1 >> v3;
    v1[0] = 10;
    std::cout << v1;
    return 0;
}