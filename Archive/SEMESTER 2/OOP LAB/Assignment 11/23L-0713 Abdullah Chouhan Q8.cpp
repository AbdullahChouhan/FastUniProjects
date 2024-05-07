#include <string>
#include <iostream>

class Employee {
    private:
        std::string name;
        int age;
    public:
        Employee(std::string name, int age) : name(name), age(age) {
            
        }
        virtual void print() {
            std::cout << "Name: " << name << ", Age: " << age << "\n";
        }
};

class HourlyEmployee : public Employee {
    private:
        double rate;
        double hours;
    public:
        HourlyEmployee(std::string name, int age, double rate, double hours) : Employee(name, age), rate(rate), hours(hours) {
            
        }
        void print() override {
            std::cout << "Hourly Employee: ";
            Employee::print();
            std::cout << "Rate: " << rate << ", Hours: " << hours << "\n";
        }
};

class SalariedEmployee : public Employee {
    private:
        double salary;
    public:
        SalariedEmployee(std::string name, int age, double salary) : Employee(name, age), salary(salary) {
            
        }
        void print() override {
            std::cout << "Salaried Employee: ";
            Employee::print();
            std::cout << "Salary: " << salary << "\n";
        }
};

int main() {
    Employee** employees = new Employee*[2];
    employees[0] = new HourlyEmployee("Employee 1", 30, 10.0, 40.0);
    employees[1] = new SalariedEmployee("Employee 2", 30, 50000.0);
    for (int i = 0; i < 2; i++) {
        employees[i]->print();
        delete employees[i];
    }
    delete[] employees;
    return 0;
}