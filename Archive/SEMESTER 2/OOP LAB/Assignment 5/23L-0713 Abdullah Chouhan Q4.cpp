#include <iostream>
#include <string>

class Product {
    private:
        int productId;
        std::string productName;
        float price;
    
    public:
        Product(int ProductId, std::string name, float price) : productId(ProductId), productName(name), price(price) {}

        Product(Product &obj) : productId(obj.productId), productName(obj.productName), price(obj.price) {}

        void setProductId(int ProductId) {
            this->productId = ProductId;
        }

        void setProductName(std::string productName) {
            this->productName = productName;
        }

        void setPrice(float price) {
            this->price = price;
        }

        int getProductId() {
            return productId;
        }

        std::string getProductName() {
            return productName;
        }

        float getPrice() {
            return price;
        }
};

int main() {
    Product Product1(1001, "Laptop", 1200.5);

    std::cout << "Product ID: " << Product1.getProductId()
    << "\nProduct Name: " << Product1.getProductName()
    << "\nPrice: " << Product1.getPrice();

    Product Product2(Product1);
    std::cout << "\n\nCopied Product Details:\nProduct ID: " << Product2.getProductId()
    << "\nProduct Name: " << Product2.getProductName()
    << "\nPrice: " << Product2.getPrice();

    return 0;
}