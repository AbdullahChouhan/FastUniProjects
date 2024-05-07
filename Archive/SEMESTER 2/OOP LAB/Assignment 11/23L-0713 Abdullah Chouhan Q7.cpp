#include <string>
#include <iostream>

class Item {
    private:
        std::string name;
        int price;
    public:
        Item(std::string name, int price) : name(name), price(price) {
            
        }
        virtual void print() {
            std::cout << name << " " << price << '\n';
        }
};

class Book : public Item {
    private:
        std::string author;
    public:
        Book(std::string name, int price, std::string author) : Item(name, price), author(author) {
            
        }
        void print() override {
            std::cout << "Book: ";
            Item::print();
            std::cout << "Author: " << author << '\n';
        }
};

class Dvd : public Item {
    private:
        std::string creator;
    public:
        Dvd(std::string name, int price, std::string creator) : Item(name, price), creator(creator) {
            
        }
        void print() override {
            std::cout << "Dvd: ";
            Item::print();
            std::cout << "Creator: " << creator << '\n';
        }
};

int main() {
    Item** items = new Item*[2];
    items[0] = new Book("Book", 100, "Author");
    items[1] = new Dvd("Dvd", 200, "Creator");
    for (int i = 0; i < 2; i++) {
        items[i]->print();
        delete items[i];
    }
    delete[] items;
    return 0;
}