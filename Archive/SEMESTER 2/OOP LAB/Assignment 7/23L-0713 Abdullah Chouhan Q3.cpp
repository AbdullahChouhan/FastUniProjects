#include <iostream>

class Distance {
    private:
        double distance;
    public:
        Distance(double distance = 0) {
            this->distance = distance;
        }
        void display() {
            std::cout << this->distance << std::endl;
        }
        bool operator< (const Distance& other) {
            return this->distance < other.distance;
        }
        bool operator> (const Distance& other) {
            return this->distance > other.distance;
        }
        bool operator<= (const Distance& other) {
            return this->distance <= other.distance;
        }
        bool operator>= (const Distance& other) {
            return this->distance >= other.distance;
        }
        Distance operator+= (const Distance& other) {
            this->distance += other.distance;
            return *this;
        }
        Distance operator+= (double other) {
            this->distance += other;
            return *this;
        }
        Distance operator-= (const Distance& other) {
            this->distance -= other.distance;
            return *this;
        }
        Distance operator-= (double other) {
            this->distance -= other;
            return *this;
        }
        bool operator&& (const Distance& other) {
            return this->distance && other.distance;
        }
        bool operator|| (const Distance& other) {
            return this->distance || other.distance;
        }
        friend std::ostream& operator<< (std::ostream& cout, const Distance& d) {
            cout << d.distance;
            return cout;
        }
        friend std::istream& operator>> (std::istream& cin, Distance& d) {
            std::cout << "Enter distance: ";
            cin >> d.distance;
            return cin;
        }
};

int main() {
    Distance d1, d2, d3;
    std::cin >> d1 >> d2;
    d3 += d1; d3 += d2;
    std::cout << "D1 = " << d1 << "\nD2 = " << d2 << "\nSum = " << d3;
    d3 -= 2.0;
    std::cout << "\nD3 after -2.0 = " << d3;
    std::cout << "\nD1 < D2 = ";
    (d1 < d2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\nD1 > D2 = ";
    (d1 > d2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\nD1 <= D2 = ";
    (d1 <= d2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\nD1 >= D2 = ";
    (d1 >= d2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\nD1 && D2 = ";
    (d1 && d2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\nD1 || D2 = ";
    (d1 || d2) ? std::cout << "true" : std::cout << "false";
    return 0;
}