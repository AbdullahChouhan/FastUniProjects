#include <iostream>
#include <cstring>

class Address {
    private:
        std::string house;
        std::string street;
        std::string city;
        std::string country;
    public:
        Address(std::string house, std::string street, std::string city, std::string country) : house(house), street(street), city(city), country(country) {}
        std::string get(int i) {
            if (i == 1) {
                return house;
            }
            else if (i == 2) {
                return street;
            }
            else if (i == 3) {
                return city;
            }
            else if (i == 4) {
                return country;
            }
            return "Invalid";
        }
};

class Student {
    private:
        std::string name;
        std::string rollno;
        Address address;
    public:
        Student(std::string name, std::string rollno, Address address) : name(name), rollno(rollno), address(address) {}
        void PrintInfo() {
            std::cout << "Name: " << name << '\n';
            std::cout << "Roll No: " << rollno << '\n';
            std::cout << "Address: " << address.get(1) << ' ' << address.get(2) << ' ' << address.get(3) << ' ' << address.get(4) << '\n';
        }
        std::string getname() {
            return name;
        }
        std::string getrollno() {
            return rollno;
        }
        Address getaddress() {
            return address;
        }
        void setname(std::string name) {
            this->name = name;
        }
        void setrollno(std::string rollno) {
            this->rollno = rollno;
        }
        void setaddress(Address address) {
            this->address = address;
        }
};

int main() {
    Student s("Abdullah Chouhan", "23L-0713", Address("1", "2", "3", "4"));
    s.PrintInfo();
}