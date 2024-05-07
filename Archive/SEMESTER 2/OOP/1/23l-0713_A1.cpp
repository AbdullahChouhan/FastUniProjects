#include <iostream>
#include <fstream> // for ifstream

using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int strLength(char* word) {
    int length = 0;
    for (; *(word + length) != '\0'; length++);
    return length;
}

bool areEqual(char* word1, char* word2) {
    for (int i = 0; *(word1 + i) != '\0' && *(word2 + i) != '\0'; i++) {
        if (toLower(*(word1 + i)) != toLower(*(word2 + i)))
            return false;
    }
    return strLength(word1) == strLength(word2);
}

char** tokenizeCharArr(char *CharArr, int size, int& wordCount) {
    wordCount = 0;
    char word[1000];
    int wordLength = 0;
    int* wordsLength = new int[size / 2];
    char** initTokArr = new char*[size];

    char char1, char2 = toLower(*CharArr);
    bool isUnique = true;
    for (int i = 0; i < size && char2 != '\0'; i++) {
        char1 = char2;
        char2 = toLower(*(CharArr + i + 1));
        if (char1 >= 'a' && char1 <= 'z') {
            word[wordLength++] = tolower(char1);
            if (char2 == ' ' || char2 == '\n' || char2 == '.' || char2 == '?' || char2 == '\0') {
                word[wordLength] = '\0';
                isUnique = true;
                for (int j = 0; j < wordCount; j++) {
                    if (areEqual(*(initTokArr + j), word)) {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique) {
                    *(initTokArr + wordCount) = new char[wordLength + 1];
                    for (int k = 0; k <= wordLength; k++)
                        *(*(initTokArr + wordCount) + k) = word[k];
                    *(wordsLength + wordCount) = wordLength;
                    wordCount++;
                }
                wordLength = 0;
            }
        }
    }
    char** tokArr = new char*[wordCount];
    for (int i = 0; i < wordCount; i++) {
        *(tokArr + i) = new char[*(wordsLength + i) + 1];
        for (int k = 0; k <= *(wordsLength + i); k++)
            *(*(tokArr + i) + k) = *(*(initTokArr + i) + k);
    }
    delete[] initTokArr, wordsLength;
    return tokArr;
}

char*** synonymArray(char** tokArr, int wordCount, int* synLengths) {
    char*** synArr = new char**[wordCount];
    char input[1000];
    char choice;
    int length = 0;
    bool isUnique = true;
    for (int i = 0; i < wordCount; i++) {
        cout << "Do you want to store synonyms for \"" << *(tokArr + i) << "\"? (y/n), any other char to stop: ";
        cin >> choice;
        choice = toLower(choice);
        if (choice == 'y') {
            while (true) {
                try {
                    cin.ignore(3, '\n');
                    cout << "Enter number of synonyms for '" << *(tokArr + i) << "': ";
                    cin >> *(synLengths + i);
                    cin.ignore(3, '\n');
                    if (cin.fail())
                        throw runtime_error("Invalid input");
                    cout << "Enter synonyms for '" << *(tokArr + i) << "'\n";
                    *(synArr + i) = new char*[*(synLengths + i)];
                    for (int j = 0; j < *(synLengths + i); j++) {
                        while (true)
                        {
                            cout << "Enter synonym " << j + 1 << ": ";
                            cin.getline(input, 1000);
                            for (length = 0; length < 1000; length++) {
                                input[length] = toLower(input[length]);
                                if (input[length] == '\0')
                                    break;
                            }
                            char* word1 = new char[length + 1];
                            for (int k = 0; k <= length; k++)
                                *(word1 + k) = input[k];
                            isUnique = true;
                            for (int k = 0; k < j; k++) {
                                if (areEqual(*(*(synArr + i) + k), word1)) {
                                    isUnique = false;
                                    break;
                                }
                            }
                            delete[] word1;
                            if (isUnique) {
                                *(*(synArr + i) + j) = new char[length + 1];
                                for (int k = 0; k <= length; k++)
                                    *(*(*(synArr + i) + j) + k) = input[k];
                                break;
                            }
                            else
                                cout << "Synonym already exists (Input is not case sensitive), try again\n";
                        }
                    }
                    break;
                }
                catch (exception& e) {
                    cout << e.what() << "\n";
                    cin.clear();
                    cin.ignore(3, '\n');
                }
            }
            if (i < wordCount - 1)
                cout << "Proceeding to next word\n";
        }
        else if (choice == 'n' || choice == 'N')
            *(synArr + i) = nullptr;
        else
            break;
    }
    return synArr;
}

void appendTokenArray(char**& arr1, int& size1, char** arr2, int size2) {
    for (int i = 0; i < size2; i++) {
        bool isUnique = true;
        for (int j = 0; j < size1; j++) {
            if (areEqual(*(arr2 + i), *(arr1 + j))) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            char** temp = new char*[size1 + 1];
            for (int k = 0; k < size1; k++) {
                *(temp + k) = *(arr1 + k);
            }
            *(temp + size1) = *(arr2 + i);
            delete[] arr1;
            arr1 = temp;
            size1++;
        }
    }
}

char* inputArray(int size, int param = 1) {
    char* CharArr = new char[size];
    cout << "Filling character array "<< param <<"\nEnter 1 for user input, 2 for input from file, any other to exit: ";
    int choice;
    cin >> choice;
    cin.ignore(3, '\n');
    if (choice == 1) {
        cout << "Enter input: ";
        cin.getline(CharArr, size);
    }
    else if (choice == 2) {
        cout << "Enter the file path: ";
        char filePath[1000];
        cin >> filePath;

        ifstream file(filePath);
        if (file.is_open()) {
            file.getline(CharArr, size, '\0'); //If it works, it works
            file.close();
        }
        else
            cout << "Failed to open file." << endl;
    }
    return CharArr;
}

void outputArray(char* CharArr, int size) {
    cout << "Outputting array\n";
    for (int i = 0; i < size || *(CharArr + i) != '\0'; i++)
        cout << *(CharArr + i);
}

void outputTokArray(char **tokArr, int wordCount) {
    cout << "Unique words: " << wordCount << '\n';
    for (int i = 0; i < wordCount; i++)
        cout << *(tokArr + i) << "\n";
}

void outputSynArray(char*** synArr, int wordCount, int synLengths[]) {
    for (int i = 0; i < wordCount; i++) {
        if (*(synArr + i) != nullptr) {
            cout << "Synonyms of " << *(synArr + i) << ": " << *(synLengths + i) << '\n';
            for (int j = 0; j < synLengths[i]; j++)
                cout << *(*(synArr + i) + j) << "\n";
        }
    }
}

void modifyCharArr2(char*& CharArr, char** tokArr, char*** synArr, int size, int wordCount, int synLengths[]) {
    char word[1000];    
    char* modifiedCharArr = nullptr, *temp = nullptr;
    int wordLength = 0, len = 0, charIndex = 0;
    int* wordsLength = new int[size / 2];
    char char1, char2 = *CharArr;
    for (int i = 0; i < size && char2 != '\0'; i++) {
        char1 = char2;
        char2 = *(CharArr + i + 1);
        if ((char1 >= 'A' && char1 <= 'Z') || (char1 >= 'a' && char1 <= 'z')) {
            word[wordLength++] = char1;
            if (char2 == ' ' || char2 == '\n' || char2 == '.' || char2 == '?' || char2 == '\0') {
                word[wordLength] = '\0';
                for (int j = 0; j < wordCount; j++) {
                    if (areEqual(*(tokArr + j), word)) {
                        for (int k = 0; k < synLengths[j]; k++) {
                            cout << "Do you want to replace \"" << word << "\" with synonym: " << *(*(synArr + j) + k) << "? (y/n): ";
                            char choice;
                            cin >> choice;
                            if (choice == 'y' || choice == 'Y') {
                                for (int l = 0; l < wordLength; l++)
                                    word[l] = toLower(word[l]);
                                if (modifiedCharArr != nullptr) {
                                    delete[] temp;
                                    int len2 = strLength(modifiedCharArr);
                                    temp = new char[len2];
                                    for (int l = 0; l < len2; l++)
                                        *(temp + l) = *(modifiedCharArr + l);
                                    delete[] modifiedCharArr;
                                }
                                else
                                    temp = CharArr;
                                len = strLength(*(*(synArr + j) + k));
                                modifiedCharArr = new char[i - wordLength + len + 1];
                                for (int l = 0; l < i - wordLength + 1; l++)
                                    *(modifiedCharArr + l) = *(temp + l);
                                for (int l = 0; l < len; l++)
                                    *(modifiedCharArr + i - wordLength + l + 1) = *(*(*(synArr + j) + k) + l);
                                *(modifiedCharArr + i - wordLength + len + 1) = '\0';
                                charIndex = i;
                                break;
                            }
                        }
                        break;
                    }
                }
                wordLength = 0;
            }
        }
    }
    delete[] wordsLength, temp;
    if (modifiedCharArr != nullptr) {
        int len = strLength(modifiedCharArr);
        for (int i = charIndex; i < size && char1 != '\0'; i++) {
            char1 = *(CharArr + i + 1);
            *(modifiedCharArr + len + i - charIndex) = char1;
        }
        delete[] CharArr;
        CharArr = modifiedCharArr;
    }
}

int main() {
    int size = 3000, wordCount = 0, wordCount2 = 0, escape = 0;
    char* CharArr = inputArray(size);
    char** tokArr = tokenizeCharArr(CharArr, size, wordCount);

    char* CharArr2 = inputArray(size, 2);
    char** tokArr2 = tokenizeCharArr(CharArr2, size, wordCount2);
    appendTokenArray(tokArr, wordCount, tokArr2, wordCount2);

    int* synLengths = new int[wordCount];
    char*** synArr = synonymArray(tokArr, wordCount, synLengths);
    modifyCharArr2(CharArr2, tokArr, synArr, size, wordCount, synLengths);
    outputArray(CharArr2, size);
    outputTokArray(tokArr, wordCount);

    for (int i = 0; i < wordCount; i++) {
        delete[] *(tokArr + i);
        for (int j = 0; j < *(synLengths + i); j++)
            delete[] *(*(synArr + i) + j);
        delete[] *(synArr + i);
    }
    for (int i = 0; i < wordCount2; i++) {
        cout << *(tokArr2 + i);
        delete[] *(tokArr2 + i);
    }
    delete[] CharArr, CharArr2, synLengths, tokArr, tokArr2, synArr;
    return 0;
}