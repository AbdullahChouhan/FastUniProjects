#include <iostream>
#include <fstream>
#include <cmath>

class String {
    private:
        char* str;
        int len;
    public:
        String(const char* s = "") {
            len = 0;
            while (s[len] != '\0')
                len++;
            str = new char[len + 1];
            for (int i = 0; i < len; i++)
                str[i] = s[i];
            str[len] = '\0';
        }
        ~String() {
            if (str != nullptr)
                delete[] str;
        }
        String(const String& other) {
            len = other.len;
            str = new char[len + 1];
            for (int i = 0; i < len; i++)
                str[i] = other.str[i];
            str[len] = '\0';
        }
        int getlen() const {
            return len;
        }
        friend std::ostream& operator<<(std::ostream& cout, const String& s) {
            cout << s.str;
            return cout;
        }
        friend std::istream& operator>>(std::istream& cin, String& s) {
            char temp[1000];
            cin >> temp;
            if (s.str != nullptr)
                delete[] s.str;
            s.len = 0;
            while (temp[s.len] != '\0')
                s.len++;
            s.str = new char[s.len + 1];
            for (int i = 0; i < s.len; i++)
                s.str[i] = temp[i];
            s.str[s.len] = '\0';
            return cin;
        }
        bool find(const String& s) {
            for (int i = 0; i < len; i++) {
                if (str[i] == s.str[0]) {
                    int j = 0;
                    while (j < s.len && str[i + j] == s.str[j]) j++;
                    if (j == s.len) {
                        return true;
                    }
                }
            }
            return false;
        }
        String operator+=(const String& other) {
            int newLen = len + other.len;
            char* temp = new char[newLen + 1];
            int i;
            for (i = 0; i < len; i++)
                temp[i] = str[i];
            for (int j = 0; j < other.len; j++)
                temp[i + j] = other.str[j];
            temp[newLen] = '\0';
            delete[] str;
            str = temp;
            len = newLen;
            return *this;
        }
        String operator+=(const char* other) {
            String s(other);
            *this += s;
            return *this;
        }
        String& operator=(const String& other) {
            if (this == &other)
                return *this;
            if (str != nullptr)
                delete[] str;
            len = other.len;
            str = new char[len + 1];
            for (int i = 0; i < len; i++) {
                str[i] = other.str[i];
            }
            str[len] = '\0';
            return *this;
        }
        String& operator=(const char* other) {
            String s(other);
            *this = s;
            return *this;
        }
        bool operator==(const String& other) {
            if (len != other.len)
                return false;
            for (int i = 0; i < len; i++) {
                if (str[i] != other.str[i])
                    return false;
            }
            return true;
        }
        bool operator==(const char* other) {
            String s(other);
            return *this == s;
        }
};

int quizzes = 0, assignments = 0; // I am sorry for my sins

class marks {
    private:
        int* marksarr;
    public:
        marks() : marksarr(nullptr) {}
        marks(const int* arr) : marksarr(new int[quizzes + assignments]) {
            for (int i = 0; i < quizzes + assignments; i++) {
                marksarr[i] = arr[i];
            }
        }
        void setmarks(int* arr) {
            if (marksarr != nullptr)
                delete[] marksarr;
            marksarr = new int[quizzes + assignments];
            for (int i = 0; i < quizzes + assignments; i++) {
                marksarr[i] = arr[i];
            }
        }
        ~marks() {
            if (marksarr != nullptr)
                delete[] marksarr;
        }
        marks operator+= (const marks& other) {
            for (int i = 0; i < quizzes + assignments; i++) {
                marksarr[i] += other.marksarr[i];
            }
            return *this; 
        }
        int*& modmarks() {
            return marksarr;
        }
        int* getmarks() const {
            return marksarr;
        }
};

class EvalReport : public marks {
    private:
        String name, rollno;
        int totalmarks;
    public:
        EvalReport(String name, String rollno, int* arr, int totalmarks) : marks(arr) {
            this->name = name;
            this->rollno = rollno;
            this->totalmarks = totalmarks;
        }
        String getname() const {
            return name;
        }
        String getrollno() const {
            return rollno;
        }
        int gettotalmarks() const {
            return totalmarks;
        }
        friend std::ostream& operator<<(std::ostream& cout, const EvalReport& er) {
            cout << er.rollno << '\t' << er.name;
            if (er.name.getlen() < 8)
                cout << "\t\t\t";
            else if (er.name.getlen() < 16)
                cout << "\t\t";
            else
                cout << "\t";
            for (int i = 0; i < quizzes + assignments; i++) {
                cout << er.getmarks()[i] << '\t';
            }
            cout << er.totalmarks;
            return cout;
        }
        EvalReport& operator=(const EvalReport& other) {
            if (this == &other)
                return *this;
            this->setmarks(other.getmarks());
            name = other.name;
            rollno = other.rollno;
            totalmarks = other.totalmarks;
            return *this;
        }
};

void UpdateStatistics(EvalReport** arr, int students, marks& max, marks& min, marks& avg, marks& avgtotals, marks& sdv) {
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < quizzes + assignments; j++) {
            if (arr[i]->getmarks()[j] > max.getmarks()[j]) {
                max.modmarks()[j] = arr[i]->getmarks()[j];
            }
            if (arr[i]->getmarks()[j] < min.getmarks()[j]) {
                min.modmarks()[j] = arr[i]->getmarks()[j];
            }
            avgtotals.modmarks()[j] += arr[i]->getmarks()[j];
        }
    }
    for (int i = 0; i < quizzes + assignments; i++) {
        avg.modmarks()[i] = avgtotals.getmarks()[i] / students;
    }
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < quizzes + assignments; j++) {
            sdv.modmarks()[j] += (arr[i]->getmarks()[j] - avg.getmarks()[j]) * (arr[i]->getmarks()[j] - avg.getmarks()[j]);
        }
    }
    for (int j = 0; j < quizzes + assignments; j++) {
        sdv.modmarks()[j] = sqrt(sdv.getmarks()[j] / students);
    }
}

void ReadDataFromFile(EvalReport**& er, int& students, int& quizzes, int& assignments, marks& max, marks& min, marks& avg, marks& avgtotals, marks& totals, marks& sdv) {
    std::ifstream file("gradesheet.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open file.\n";
        return;
    }
    file >> students >> quizzes >> assignments;
    int* gradings = new int[quizzes + assignments];
    for (int i = 0; i < quizzes + assignments; i++) {
        file >> gradings[i];
    }
    int* emptymarks = new int[quizzes + assignments];
    for (int i = 0; i < quizzes + assignments; i++) {
        emptymarks[i] = 0;
    }
    max.setmarks(emptymarks);
    min.setmarks(gradings);
    totals.setmarks(gradings);
    avg.setmarks(emptymarks);
    avgtotals.setmarks(emptymarks);
    sdv.setmarks(emptymarks);
    delete[] gradings;
    er = new EvalReport*[students];
    for (int i = 0; i < students; i++) {
        String name, lastname, rollno;
        file >> name;
        name += " ";
        file >> lastname;
        name += lastname;
        file >> rollno;
        int totalmarks = 0;
        int* arr = new int[quizzes + assignments];
        for (int j = 0; j < quizzes + assignments; j++) {
            file >> arr[j];
            totalmarks += arr[j];
        }
        er[i] = new EvalReport(name, rollno, arr, totalmarks);
        delete[] arr;
    }
    UpdateStatistics(er, students, max, min, avg, avgtotals, sdv);
}

void PrintAll(EvalReport** arr, int students) {
    if (students == 0) {
        std::cout << "No students found.\n";
        return;
    }
    std::cout << "Roll No. \tName\t\t\t";
    for (int i = 0; i < quizzes; i++) {
        std::cout << "Q" << i + 1 << '\t';
    }
    for (int i = 0; i < assignments; i++) {
        std::cout << "A" << i + 1 << '\t';
    }
    std::cout << "Total\n";
    for (int i = 0; i < students; i++) {
        std::cout << *arr[i] << std::endl;
    }
}

EvalReport** SearchStudentsbyKeyWord(EvalReport** arr, int students, String key, int& count) {
    bool indexes[students];
    for (int i = 0; i < students; i++) {
        if (arr[i]->getname().find(key) || arr[i]->getrollno().find(key)) {
            count++;
            indexes[i] = true;
        }
    }
    EvalReport** arr2 = new EvalReport*[count];
    for (int i = 0, j = 0; i < students; i++) {
        if (indexes[i] == true) {
            arr2[j] = arr[i];
            j++;
        }
    }
    return arr2;
}

void SortListByTotal(EvalReport** arr, int students) {
    for (int i = 0; i < students - 1; i++) {
        for (int j = 0; j < students - i - 1; j++) {
            if (arr[j]->gettotalmarks() < arr[j + 1]->gettotalmarks()) {
                EvalReport* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintDetailView(String rollno, EvalReport** arr, int students, const marks& max, const marks& min, const marks& avg, const marks& totals, const marks& sdv) {
    for (int i = 0; i < students; i++) {
        if (arr[i]->getrollno() == rollno) {
            std::cout << "Assignment:\n";
            std::cout << "Assignment #\tObtained Marks\tTotal Marks\tAverage\t\tStandard Deviation\tMinimum\t\tMaximum\n";
            for (int j = 0; j < assignments; j++) {
                std::cout << j + 1 << "\t\t";
                std::cout << arr[i]->getmarks()[j] << "\t\t";
                std::cout << totals.getmarks()[j] << "\t\t";
                std::cout << avg.getmarks()[j] << "\t\t";
                std::cout << sdv.getmarks()[j] << "\t\t\t";
                std::cout << min.getmarks()[j] << "\t\t";
                std::cout << max.getmarks()[j] << std::endl;
            }
            std::cout << "\nQuiz:\n";
            std::cout << "Quiz #\t\tObtained Marks\tTotal Marks\tAverage\t\tStandard Deviation\tMinimum\t\tMaximum\n";
            for (int j = assignments; j < quizzes + assignments; j++) {
                std::cout << j - assignments + 1 << "\t\t";
                std::cout << arr[i]->getmarks()[j] << "\t\t";
                std::cout << totals.getmarks()[j] << "\t\t";
                std::cout << avg.getmarks()[j] << "\t\t";
                std::cout << sdv.getmarks()[j] << "\t\t\t";
                std::cout << min.getmarks()[j] << "\t\t";
                std::cout << max.getmarks()[j] << std::endl;
            }
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void PrintStatistics(marks& max, marks& min, marks& avg, marks& gradings) {
    std::cout << "\t";
    for (int i = 0; i < quizzes; i++) {
        std::cout << "Q" << i + 1 << '\t';
    }
    for (int i = 0; i < assignments; i++) {
        std::cout << "A" << i + 1 << '\t';
    }
    std::cout << "\nTotal:\t";
    for (int i = 0; i < quizzes + assignments; i++) {
        std::cout << gradings.getmarks()[i] << '\t';
    }
    std::cout << "\nMax:\t";
    for (int i = 0; i < quizzes + assignments; i++) {
        std::cout << max.getmarks()[i] << '\t';
    }
    std::cout << "\nMin:\t";
    for (int i = 0; i < quizzes + assignments; i++) {
        std::cout << min.getmarks()[i] << '\t';
    }
    std::cout << "\nAvg:\t";
    for (int i = 0; i < quizzes + assignments; i++) {
        std::cout << avg.getmarks()[i] << '\t';
    }
    std::cout << "\n------------------------------------------------------------------\n";
}

int main() {
    int students;
    marks min, max, avg, avgtotals, totals, sdv;
    EvalReport** arr;
    ReadDataFromFile(arr, students, quizzes, assignments, max, min, avg, avgtotals, totals, sdv);
    PrintStatistics(max, min, avg, totals);
    PrintAll(arr, students);
    std::cout << "Enter roll number/name to search: ";
    String key;
    std::cin >> key;
    int count = 0;
    EvalReport** arr2 = SearchStudentsbyKeyWord(arr, students, key, count);
    PrintAll(arr2, count);
    SortListByTotal(arr, students);
    std::cout << "Sorted List:-\n";
    PrintAll(arr, students);
    std::cout << "Enter roll number to view detail: ";
    std::cin >> key;
    PrintDetailView(key, arr, students, max, min, avg, totals, sdv);
    for (int i = 0; i < students; i++) {
        delete arr[i];
    }
    delete[] arr;
    delete[] arr2;
    return 0;
}