#include <iostream>
#include <string>

using namespace std;
class GradeBook
{
public:
    void setCourseName(string name)
    {
        courseName = name;
    } // end function setCourseName
    string getCourseName() const
    {
        return courseName;
    } // end function getCourseName
    void displayMessage() const
    {
        cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    } // end function displayMessage
private:
    string courseName;
}; // end class GradeBook
int main()
{
    string nameOfCourse;
    GradeBook myGradeBook;
    cout << "Initial course name is: " << endl;
    cout << "\nPlease enter the course name:" << endl;
    getline(cin, nameOfCourse );
    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;
    myGradeBook.displayMessage();
}