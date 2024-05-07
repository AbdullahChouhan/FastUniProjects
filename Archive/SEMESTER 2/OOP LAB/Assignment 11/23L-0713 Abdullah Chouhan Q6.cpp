#include <iostream>
#include <cstring>

class Student {
    private:
        std::string firstName, lastName;
        int age;
        double cgpa;
    public:
        Student(std::string firstName, std::string lastName, int age, double cgpa) : firstName(firstName), lastName(lastName), age(age), cgpa(cgpa) {
            std::cout << "Student called\n";
        }
        double getCgpa() {
            return cgpa;
        }
        void setCgpa(double cgpa) {
            this->cgpa = cgpa;
        }
        ~Student() {
            std::cout << "Student destroyed\n";
        }
};

class Undergraduate : public Student {
    private:
        std::string fyp_name;
    public:
        Undergraduate(std::string firstName, std::string lastName, int age, double cgpa, std::string fyp_name) : Student(firstName, lastName, age, cgpa), fyp_name(fyp_name) {
            std::cout << "Undergraduate called\n";
        }
        std::string getMajor() {
            return fyp_name;
        }
        void setMajor(std::string fyp_name) {
            this->fyp_name = fyp_name;
        }
        ~Undergraduate() {
            std::cout << "Undergraduate destroyed\n";
        }
};

class Graduate : public Student {
    private:
        std::string fyp_name;
    public:
        Graduate(std::string firstName, std::string lastName, int age, double cgpa, std::string fyp_name) : Student(firstName, lastName, age, cgpa), fyp_name(fyp_name) {
            std::cout << "Graduate called\n";
        }
        std::string getMajor() {
            return fyp_name;
        }
        void setMajor(std::string fyp_name) {
            this->fyp_name = fyp_name;
        }
        ~Graduate() {
            std::cout << "Graduate destroyed\n";
        }
};

int main() {
    Student** students = new Student*[2];
    students[0] = new Undergraduate("John", "Doe", 18, 3.5, "Computer Science");
    students[1] = new Graduate("Jane", "Doe", 19, 3.8, "Computer Science");
    for (int i = 0; i < 2; i++) {
        std::cout << students[i]->getCgpa();
        delete students[i];
    }
    delete[] students;
    return 0;
}