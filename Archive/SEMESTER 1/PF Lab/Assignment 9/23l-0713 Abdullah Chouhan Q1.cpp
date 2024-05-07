#include <iostream>
using namespace std;
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
int main()
{
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

    return 0;
}