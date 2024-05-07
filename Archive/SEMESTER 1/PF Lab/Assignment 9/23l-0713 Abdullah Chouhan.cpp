#include <iostream>
using namespace std;
//Program 1
int countWords(char paragraph[], int sizeOfParagraph){
    if (sizeOfParagraph < 2)
        return 0;
    sizeOfParagraph -= 2;
    int words = 0;
    for (int i = 0; i < sizeOfParagraph; i++) {
        if ((paragraph[i] != ' ' && paragraph[i] != '\n') && (paragraph[i + 1] == ' ' || paragraph[i + 1] == '\n'))
            words++;
    }
    if (paragraph[sizeOfParagraph] != ' ' && paragraph[sizeOfParagraph] != '\n')
        words++;
    return words;
}
//Program 2
void merge(char array1[], char array2[], char array3[], int size1, int size2){
    int i;
    for (i = 0; i < size1 - 1; i++)
        array3[i] = array1[i];
    for (int j = 0; j < size2; j++, i++){    
        array3[i] = array2[j];
    }
}

int main()
{
    int choice;
    cout << "Enter question number between 1 and 2 to run code, otherwise to exit: ";
    cin >> choice;
    if (choice == 1)
    {
        //Program 1
        char p1[] = "This is first paragraph with no space at start and no space at end";
        char p2[] = " This is first paragraph with one space at start and no space at end";
        char p3[] = " This is first paragraph with one space at start and one space at end ";
        char p4[] = "    this is a  sparse     paragraph     ";
        char p5[] = "    it is   multiline paragraph \n second line of paragraph ";
        cout << "Word Count of p1 is " << countWords(p1,sizeof(p1)) << '\n';
        cout << "Word Count of p2 is " << countWords(p2,sizeof(p2)) << '\n';
        cout << "Word Count of p3 is " << countWords(p3,sizeof(p3)) << '\n';
        cout << "Word Count of p4 is " << countWords(p4,sizeof(p4)) << '\n';
        cout << "Word Count of p5 is " << countWords(p5,sizeof(p5));
    }
    else if (choice == 2)
    {
        //Program 2
        char p1[] = "This is first paragraph with no space at start and no space at end";
        int p1_size = sizeof(p1);
        char p2[] = " This is first paragraph with one space at start and no space at end";
        int p2_size = sizeof(p2);
        int p3_size = sizeof(p1) + sizeof(p2);
        char p3[p3_size - 1];
        merge(p1,p2,p3,p1_size,p2_size);
        cout << p3;
    }
    return 0;
}