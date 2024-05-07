#include <string>
#include <iostream>

class Vehicle {
    private:
        std::string name;
    public:
        Vehicle(std::string name) : name(name) {
            
        }
        virtual void print() {
            std::cout << name << '\n';
        }
};

class Car : public Vehicle {
    public:
        Car(std::string name) : Vehicle(name) {
            
        }
        void print() override {
            std::cout << "Car: ";
            Vehicle::print();
        }
};

class Motorcycle : public Vehicle {
    public:
        Motorcycle(std::string name) : Vehicle(name) {
            
        }
        void print() override {
            std::cout << "Motorcycle: ";
            Vehicle::print();
        }
};

int main() {
    Vehicle** vehicles = new Vehicle*[2];
    vehicles[0] = new Car("Car");
    vehicles[1] = new Motorcycle("Motorcycle");
    for (int i = 0; i < 2; i++) {
        vehicles[i]->print();
        delete vehicles[i];
    }
    delete[] vehicles;
    return 0;
}