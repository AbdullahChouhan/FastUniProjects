#include <iostream>
using namespace std;

void merge(char array1[], char array2[], char array3[], int size1, int size2){
    int i;
    for (i = 0; i < size1 - 1; i++)
        array3[i] = array1[i];
    for (int j = 0; j < size2; j++, i++){    
        array3[i] = array2[j];
    }
}

int main(int argc, char *argv[])
{
    char p1[] = "This is first paragraph";
    int p1_size = sizeof(p1);
    char p2[] = " Second paragraph";
    int p2_size = sizeof(p2);
    int p3_size = sizeof(p1) + sizeof(p2);
    char p3[p3_size - 1];
    merge(p1,p2,p3,p1_size,p2_size);
    cout << p3;
    return 0;
}