#include <iostream>
#include <fstream>

using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int strLength(char* word) {
    int length = 0;
    for (; word[length] != '\0'; length++);
    return length;
}

void stringConcatenate(char* cstring1, char* cstring2) {
    int i = strLength(cstring1), j = 0;
    while (cstring2[j] != '\0') {
        cstring1[i] = cstring2[j];
        i++;
        j++;
    }
    cstring1[i] = '\0';
}

char** stringTokens(char *charArr, int& wordCount) {
    wordCount = 0;
    int size = strLength(charArr), wordLength = 0;
    char word[1000];
    int* wordsLength = new int[size / 2];
    char** initTokArr = new char*[size];
    char char1, char2 = charArr[0];

    for (int i = 0; i < size && char2 != '\0'; i++) {
        char1 = char2;
        char2 = charArr[i + 1];
        if (!(char1 == ' ' || char1 == '\n' || char1 == '.' || char1 == '?' || char1 == '\0')) {
            word[wordLength++] = char1;
            if (char2 == ' ' || char2 == '\n' || char2 == '.' || char2 == '?' || char2 == '\0') {
                word[wordLength] = '\0';
                initTokArr[wordCount] = new char[wordLength + 1];
                for (int k = 0; k <= wordLength; k++)
                    initTokArr[wordCount][k] = word[k];
                wordsLength[wordCount] = wordLength;
                wordCount++;
                wordLength = 0;
            }
        }
    }
    char** tokArr = new char*[wordCount];
    for (int i = 0; i < wordCount; i++) {
        tokArr[i] = new char[wordsLength[i] + 1];
        for (int k = 0; k <= wordsLength[i]; k++)
            tokArr[i][k] = initTokArr[i][k];
    }
    delete[] initTokArr, wordsLength;
    return tokArr;
}

char** inverseStringTokens(char* charArr, int& wordCount) {
    char** inverseTokArr = stringTokens(charArr, wordCount);
    for (int i = 0; i < wordCount / 2; i++) {
        char* temp = inverseTokArr[i];
        inverseTokArr[i] = inverseTokArr[wordCount - i - 1];
        inverseTokArr[wordCount - i - 1] = temp;
    }
    return inverseTokArr;
}

char* reverseSentence(char* charArr) {
    int wordCount = 0;
    char** tokArr = inverseStringTokens(charArr, wordCount), gap[2] = {" "};
    charArr[0] = '\0';
    for (int i = 0; i < wordCount; i++) {
        stringConcatenate(charArr, tokArr[i]);
        if (i != wordCount - 1)
            stringConcatenate(charArr, gap);
    }
    return charArr;
}

int CompareString(char* string1, char* string2) {
    char char1, char2;
    for (int i = 0; (char1 = string1[i]) != '\0' && (char2 = string2[i]) != '\0'; i++) {
        if (toLower(char1) > toLower(char2))
            return 1;
        else if (toLower(char1) < toLower(char2))
            return -1;
    }
    return 0;
}

void sortArray(char** tokArr, int wordCount) {
    bool noMoreSwaps = false;
    char* temp;
    while (!noMoreSwaps) {
        noMoreSwaps = true;
        for (int i = 0; i < wordCount - 1; i++) {
            if (CompareString(tokArr[i], tokArr[i + 1]) > 0) {
                temp = tokArr[i];
                tokArr[i] = tokArr[i + 1];
                tokArr[i + 1] = temp;
                noMoreSwaps = false;
            }
        }
        --wordCount;
    }
}

void compressString(char*& charArr) {
    int i = 0, j = 0;
    while (charArr[i] != '\0') {
        charArr[j] = charArr[i++];
        while (charArr[i] == charArr[i - 1])
            i++;
        j++;
    }
    charArr[j] = '\0';
}

void outputTokArray(char** tokArr, int wordCount) {
    for (int i = 0; i < wordCount; i++)
        cout << tokArr[i] << "\n";
}

void inputString(ifstream& file, char*& string1, char* input_string) {
    int len = 0;
    file.getline(input_string, 1000);
    string1 = new char[(len = strLength(input_string)) + 1];
    for (int i = 0; i < len; i++)
        string1[i] = input_string[i];
    string1[len] = '\0';
    file.getline(input_string, 3);
    input_string[0] = '\0';
}

void input(ifstream& file, char*& string1, char*& string2, char*& string3, char**& totalStudents, int& totalStudentsCount) {
    if (file.is_open()) {
        char* input_string = new char[1000];
        int len = 0;

        inputString(file, string1, input_string);
        inputString(file, string2, input_string);
        inputString(file, string3, input_string);

        file >> totalStudentsCount >> ws;
        totalStudents = new char*[totalStudentsCount];
        for (int i = 0; i < totalStudentsCount; i++) {
            file.getline(input_string, 1000);
            totalStudents[i] = new char[(len = strLength(input_string)) + 1];
            for(int j = 0; j < len; j++)
                totalStudents[i][j] = input_string[j];
            totalStudents[i][len] = '\0';
            input_string[0] = '\0';
        }
    }
}

int main() {
    ifstream file("Data.txt");
    if (!file.is_open()) {
        cout << "Failed to open file.\n";
        return 0;
    }
    char* string1 = nullptr, *string2 = nullptr, *string3 = nullptr, **totalStudents = nullptr;
    int totalStudentsCount = 0;
    input(file, string1, string2, string3, totalStudents, totalStudentsCount);
    file.close();
    
    cout << "String 1:\t\t" << string1 << "\n";
    cout << "String 2:\t\t" << string2 << "\n";

    stringConcatenate(string1, string2);
    cout << "After concatenation:\n";
    cout << "String 1:\t\t" << string1 << "\n";
    cout << "String 2:\t\t" << string2 << "\n\n";
    
    cout << "Testing StringTokens:\nTokens of string 1 are as follows:\n";
    int words1 = 0;
    char** string1Tokens = stringTokens(string1, words1);
    outputTokArray(string1Tokens, words1);

    cout << "\nTesting InverseStringTokens:\nTokens of string 1 in reverse order are as follows:\n";
    char** inverseString1Tokens = inverseStringTokens(string1, words1);
    outputTokArray(inverseString1Tokens, words1);

    cout << "\nTesting ReverseSentence\nReverse sentence of string 1 is:\t\"";
    char* reverseString1 = reverseSentence(string1);
    cout << reverseString1 << "\"\n\n";

    cout << "Unsorted list:-\n";
    outputTokArray(totalStudents, totalStudentsCount);
    cout << "\nSorted list:-\n";
    sortArray(totalStudents, totalStudentsCount);
    outputTokArray(totalStudents, totalStudentsCount);

    cout << "\nUncompressed string:\t" << string3 << "\n";
    compressString(string3);
    cout << "Compressed string:\t" << string3 << "\n";

    for (int i = 0; i < words1; i++)
        delete[] string1Tokens[i], inverseString1Tokens[i];
    for(int i = 0; i < totalStudentsCount; i++)
        delete[] totalStudents[i];
    delete[] string1, string2, string3, totalStudents, string1Tokens, inverseString1Tokens, reverseString1;
    return 0;
}