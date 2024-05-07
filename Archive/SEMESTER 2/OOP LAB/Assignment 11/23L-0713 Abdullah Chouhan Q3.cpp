#include <string>
#include <iostream>

class Animal {
    private:
        std::string name;
    public:
        Animal(std::string name) : name(name) {
            
        }
        virtual void print() {
            std::cout << name << '\n';
        }
};

class Dog : public Animal {
    public:
        Dog(std::string name) : Animal(name) {
            
        }
        void print() override {
            std::cout << "Dog: ";
            Animal::print();
        }
};

class Cat : public Animal {
    public:
        Cat(std::string name) : Animal(name) {
            
        }
        void print() override {
            std::cout << "Cat: ";
            Animal::print();
        }
};

class Bird : public Animal {
    public:
        Bird(std::string name) : Animal(name) {
            
        }
        void print() override {
            std::cout << "Bird: ";
            Animal::print();
        }
};

int main() {
    Animal** animals = new Animal*[3];
    animals[0] = new Dog("Dog");
    animals[1] = new Cat("Cat");
    animals[2] = new Bird("Bird");
    for (int i = 0; i < 3; i++) {
        animals[i]->print();
        delete animals[i];
    }
    delete[] animals;
    return 0;
}