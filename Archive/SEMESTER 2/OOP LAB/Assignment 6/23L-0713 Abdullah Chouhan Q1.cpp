#include <iostream>

int strLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

class stringInfo {
    private:
        char* str = nullptr;
        int length = 0;

    public:
        stringInfo(const char* str = "\0") {
            while (str[length] != '\0') length++;
            this->str = new char[length + 1];
            for (int i = 0; i <= length; i++) {
                this->str[i] = str[i];
            }
        }
        void display() {
            std::cout << "String: \"" << str << "\"\n"
            << "Length: " << length << ".\n";
        }
        ~stringInfo() {
            if (str != nullptr) delete[] str;
        }
};

int main() {
    stringInfo s1("Testing stringInfo class");
    s1.display();
    
    return 0;
}