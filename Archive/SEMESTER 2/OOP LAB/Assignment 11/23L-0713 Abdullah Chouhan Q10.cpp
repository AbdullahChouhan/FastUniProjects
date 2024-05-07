#include <string>
#include <iostream>

class MenuItem {
    private:
        std::string name;
        int price;
    public:
        MenuItem(std::string name, int price) : name(name), price(price) {
            
        }
        virtual void print() {
            std::cout << name << " " << price << '\n';
        }
};

class Appetizer : public MenuItem {
    public:
        Appetizer(std::string name, int price) : MenuItem(name, price) {
            
        }
        void print() override {
            std::cout << "Appetizer: ";
            MenuItem::print();
        }
};

class MainCourse : public MenuItem {
    public:
        MainCourse(std::string name, int price) : MenuItem(name, price) {
            
        }
        void print() override {
            std::cout << "MainCourse: ";
            MenuItem::print();
        }
};

class Dessert : public MenuItem {
    public:
        Dessert(std::string name, int price) : MenuItem(name, price) {
            
        }
        void print() override {
            std::cout << "Dessert: ";
            MenuItem::print();
        }
};

int main() {
    MenuItem** items = new MenuItem*[3];
    items[0] = new Appetizer("Appetizer", 100);
    items[1] = new MainCourse("MainCourse", 200);
    items[2] = new Dessert("Dessert", 300);
    for (int i = 0; i < 3; i++) {
        items[i]->print();
        delete items[i];
    }
    delete[] items;
    return 0;
}