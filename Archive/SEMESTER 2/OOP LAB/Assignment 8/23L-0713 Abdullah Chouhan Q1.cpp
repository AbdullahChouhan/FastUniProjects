#include <iostream>
#include <string>

class Engine {
    private:
        int horsePower;
        std::string type;
    public:
        Engine(int horsePower, std::string type) : horsePower(horsePower), type(type) {}
        Engine(Engine &obj) : horsePower(obj.horsePower), type(obj.type) {}
        void setHorsePower(int horsePower) {
            this->horsePower = horsePower;
        }
        void setType(std::string type) {
            this->type = type;
        }
        int getHorsePower() {
            return horsePower;
        }
        std::string getType() {
            return type;
        }
};

class Car {
    private:
        std::string name, model;
        int year;
        Engine engine;
    public:
        Car(std::string name, std::string model, int year, Engine engine) : name(name), model(model), year(year), engine(engine) {}
        Car(Car &obj) : name(obj.name), model(obj.model), year(obj.year), engine(obj.engine) {}
        void setName(std::string name) {
            this->name = name;
        }
        void setModel(std::string model) {
            this->model = model;
        }
        void setYear(int year) {
            this->year = year;
        }
        void setEngine(Engine engine) {
            this->engine = engine;
        }
        std::string getName() {
            return name;
        }
        std::string getModel() {
            return model;
        }
        int getYear() {
            return year;
        }
        Engine getEngine() {
            return engine;
        }
};

int main() {
    Car Car1("BMW", "X5", 2020, Engine(150, "diesel"));
    std::cout << "Car details: "
    << "\nName: " << Car1.getName()
    << "\nModel: " << Car1.getModel()
    << "\nYear: " << Car1.getYear()
    << "\nEngine: " << Car1.getEngine().getType()
    << "\nHorse Power: " << Car1.getEngine().getHorsePower();
}