#include <iostream>
#include <cstring>

class Student {
    private:
        char name[50];
    public:
        Student(char name[50]) {
            strcpy(this->name, name);
        }
        void PrintInfo() {
            std::cout << name << '\n';
        }
};

class Society {
    private:
        char name[50];
        Student* president;
        Student* members[5];
    public:
        Society(const char* name, Student* president = nullptr, Student* members[5] = nullptr) {
            strcpy(this->name, name);
            this->president = president;
            for (int i = 0; i < 5; i++) {
                this->members[i] = nullptr;
            }
        }
        void PrintInfo() {
            std::cout << "Society Name: " << name
                      << "\nPresident:\t";
            if (president != nullptr) {
                president->PrintInfo();
            }
            else {
                std::cout << "Not Available\n";
            }
            for (int i = 0; i < 5; i++) {
                std::cout << "Member " << i + 1 << ":\t";
                if (members[i] != nullptr) {
                    members[i]->PrintInfo();
                }
                else {
                    std::cout << "Not Available\n";
                }
            }
        }
};

int main() {
    Society sports("Sports");
    sports.PrintInfo();
}