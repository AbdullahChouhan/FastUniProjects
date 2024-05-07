#include <iostream>
using namespace std;

void reverseSentence(char paragraph[], int sizeOfParagraph){
    int start = 0;
    char temp;
    if (sizeOfParagraph > 1)
    {
        cout << "Count: " << sizeOfParagraph << '\n';
        sizeOfParagraph -= 2;
        for (int i = 0; i <= sizeOfParagraph; i++) {
            if ((paragraph[i] != ' ' && paragraph[i] != '\n') && (paragraph[i + 1] == ' ' || paragraph[i + 1] == '\n'))
            {
                for (int j = i; j >= start; j--)
                    cout << paragraph[j];
                start = i + 1;
            }
        }
        if (paragraph[sizeOfParagraph] != ' ' && paragraph[sizeOfParagraph] != '\n')
        {
            for (int j = sizeOfParagraph; j >= start; j--)
                cout << paragraph[j];  
        }
        cout << '\n';
    }
}
int main()
{
    char p1[] = "This is first paragraph with no space at start and no space at end";
    char p2[] = " This is first paragraph with one space at start and no space at end";
    char p3[] = " This is first paragraph with one space at start and one space at end ";
    char p4[] = "    this is a  sparse     paragraph     ";
    char p5[] = "    it is   multiline paragraph \n second line of paragraph ";
    reverseSentence(p1,sizeof(p1));
    reverseSentence(p2,sizeof(p2));
    reverseSentence(p3,sizeof(p3));
    reverseSentence(p4,sizeof(p4));
    reverseSentence(p5,sizeof(p5));
    return 0;
}