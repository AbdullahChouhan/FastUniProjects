#include <string>
#include <iostream>

class Employee {
    private:
        std::string name;
        int age;
    public:
        Employee(std::string name, int age) : name(name), age(age) {
            
        }
        void print() {
            std::cout << "Name: " << name << ", Age: " << age << "\n";
        }
};

class Manager : public Employee {
    private:
        std::string department;
    public:
        Manager(std::string name, int age, std::string department) : Employee(name, age), department(department) {
            
        }
};

class Developer : public Employee {
    private:
        std::string language;
    public:
        Developer(std::string name, int age, std::string language) : Employee(name, age), language(language) {
            
        }
};

int main() {
    Employee** employees = new Employee*[3];
    for (int i = 0; i < 3; i++) {
        employees[i] = new Employee("Employee " + std::to_string(i), 30);
        employees[i]->print();
        delete employees[i];
    }
    delete[] employees;
    return 0;
}