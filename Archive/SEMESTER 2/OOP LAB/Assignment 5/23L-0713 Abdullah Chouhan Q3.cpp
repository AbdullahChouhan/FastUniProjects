#include <iostream>
#include <string>

class Student {
    private:
        int StudentId;
        std::string name;
        char grade;
        float GPA;
    
    public:
        Student(int StudentId, std::string name, char grade, float GPA) : StudentId(StudentId), name(name), grade(grade), GPA(GPA) {}

        void SetStudentId(int StudentId) {
            this->StudentId = StudentId;
        }

        void SetName(std::string name) {
            this->name = name;
        }

        void SetGrade(char grade) {
            this->grade = grade;
        }

        void SetGPA(float GPA) {
            this->GPA = GPA;
        }

        int GetStudentId() {
            return StudentId;
        }

        std::string GetName() {
            return name;
        }

        char GetGrade() {
            return grade;
        }

        float GetGPA() {
            return GPA;
        }
};

int main() {
    Student Student1(101, "John Doe", 'A', 3.75);
    std::cout << "Student ID: " << Student1.GetStudentId()
    << "\nName: " << Student1.GetName()
    << "\nGrade: " << Student1.GetGrade()
    << "\nGPA: " << Student1.GetGPA();
    Student1.SetGrade('B');
    Student1.SetGPA(3.5);

    std::cout << "\n\nUpdated Details:\nGrade: " << Student1.GetGrade()
    << "\nGPA: " << Student1.GetGPA();

    return 0;
}