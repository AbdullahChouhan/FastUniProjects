#include <string>
#include <iostream>

class Product {
    private:
        std::string name;
        int price;
    public:
        Product(std::string name, int price) : name(name), price(price) {
            
        }
        virtual void print() {
            std::cout << name << " " << price << '\n';
        }
};

class Electronics : public Product {
    private:
        std::string brand;
    public:
        Electronics(std::string name, int price, std::string brand) : Product(name, price), brand(brand) {
            
        }
        void print() override {
            std::cout << "Electronics: ";
            Product::print();
            std::cout << "Brand: " << brand << '\n';
        }
};

class Clothing : public Product {
    private:
        std::string Fabric;
    public:
        Clothing(std::string name, int price, std::string Fabric) : Product(name, price), Fabric(Fabric) {
            
        }
        void print() override {
            std::cout << "Clothing: ";
            Product::print();
            std::cout << "Fabric: " << Fabric << '\n';
        }
};

int main() {
    Product** products = new Product*[2];
    products[0] = new Electronics("Electronics", 100, "Brand");
    products[1] = new Clothing("Clothing", 200, "Fabric");
    for (int i = 0; i < 2; i++) {
        products[i]->print();
        delete products[i];
    }
    delete[] products;
    return 0;
}