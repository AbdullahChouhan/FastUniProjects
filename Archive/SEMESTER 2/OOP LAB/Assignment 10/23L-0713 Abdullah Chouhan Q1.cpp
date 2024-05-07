#include <iostream>
#include <cstring>

class Person {
    private:
        std::string firstName, lastName;
    protected:
        int age;
    public:
        Person(std::string firstName, std::string lastName, int age) : firstName(firstName), lastName(lastName), age(age) {
            std::cout << "Person called\n";
        }
        std::string getFirstName() {
            return firstName;
        }
        std::string getLastName() {
            return lastName;
        }
        int getAge() {
            return age;
        }
        void setFirstName(std::string firstName) {
            this->firstName = firstName;
        }
        void setLastName(std::string lastName) {
            this->lastName = lastName;
        }
        void setAge(int age) {
            this->age = age;
        }
        ~Person() {
            std::cout << "Person destroyed\n";
        }
};

class Faculty : public Person {
    private:
        std::string department;
        int courseCount;
    public:
        Faculty(std::string firstName, std::string lastName, int age, std::string department, int courseCount) : Person(firstName, lastName, age), department(department), courseCount(courseCount) {
            std::cout << "Faculty called\n";
        }
        std::string getDepartment() {
            return department;
        }
        int getCourseCount() {
            return courseCount;
        }
        void setDepartment(std::string department) {
            this->department = department;
        }
        void setCourseCount(int courseCount) {
            this->courseCount = courseCount;
        }
        ~Faculty() {
            std::cout << "Faculty destroyed\n";
        }
};

class Student : public Person {
    private:
        double cgpa;
    public:
        Student(std::string firstName, std::string lastName, int age, double cgpa) : Person(firstName, lastName, age), cgpa(cgpa) {
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
    Person p("Abdullah", "Chouhan", 19);
    Student s("Abdullah", "Chouhan", 19, 3.5);
    Undergraduate u("Abdullah", "Chouhan", 19, 3.5, "Social Media");
    std::cout << p.getFirstName() << " " << s.getCgpa() << " " << u.getMajor() << "\n";
}