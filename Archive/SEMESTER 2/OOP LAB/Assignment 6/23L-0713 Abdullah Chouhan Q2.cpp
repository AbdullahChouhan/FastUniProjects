#include <iostream>
#include <cstring>

class StringArray
{
private:
    char **strings = nullptr;
    int size;

public:
    StringArray(int arraySize) : size(arraySize)
    {
        // Constructor to initialize the StringArray with a given size
        strings = new char *[size];
        for (int i = 0; i < size; i++)
            strings[i] = new char[100];
    }
    ~StringArray()
    {
        // Destructor to free the dynamically allocated memory
        for (int i = 0; i < size; i++)
            delete[] strings[i];
        delete[] strings;
    }
    void setString(int index, const char *str)
    {
        // Method to set a string at a specific index
        // Since <cstring> was included, I will use its strcpy() function
        strcpy(strings[index], str);
    }
    const char *getString(int index)
    {
        // Method to get the string at a specific index
        return strings[index];
    }
};
int main()
{
    StringArray stringArray(3);
    stringArray.setString(0, "Hello");
    std::cout << "String at index 0: " << stringArray.getString(0) << std::endl;
    return 0;
}