#include <iostream>

class stringHolder {
    private:
        char* string_ptr = nullptr;

    public:
        stringHolder(const char* str = "\0") {
            int length = 0;
            while (str[length] != '\0') length++;
            string_ptr = new char[length + 1];
            for (int i = 0; i <= length; i++) {
                string_ptr[i] = str[i];
            }
        }
        stringHolder(stringHolder& obj) {
            int length = 0;
            while (obj.string_ptr[length] != '\0') length++;
            string_ptr = new char[length + 1];
            for (int i = 0; i <= length; i++) {
                string_ptr[i] = obj.string_ptr[i];
            }
        }
        stringHolder(stringHolder* obj) {
            string_ptr = obj->string_ptr;
        }
        void setstring(const char* str = "\0") {
            this->~stringHolder();
            int length = 0;
            while (str[length] != '\0') length++;
            string_ptr = new char[length + 1];
            for (int i = 0; i <= length; i++) {
                string_ptr[i] = str[i];
            }
        }
        void display() {
            std::cout << "String: \"" << string_ptr << "\"\n";
        }
        ~stringHolder() {
            if (string_ptr != nullptr) delete[] string_ptr;
        }
};
int main() {
    stringHolder s1("Hello");
    s1.display();
    s1.setstring("Deep copy");
    stringHolder deepcopy(s1);
    std::cout << "Before alteration:\nNew ";
    deepcopy.display();
    s1.display();
    s1.setstring("Altered Deep copy");
    std::cout << "After alteration:\nNew ";
    deepcopy.display();
    s1.display();
    stringHolder* s2 = new stringHolder("Shallow copy");
    stringHolder shallowcopy(s2);
    std::cout << "Before alteration:\nNew ";
    shallowcopy.display();
    s2->display();
    s2->setstring("Altered Shallow copy");
    std::cout << "After alteration:\nNew ";
    shallowcopy.display();
    s2->display();
    delete s2;
    return 0;
}