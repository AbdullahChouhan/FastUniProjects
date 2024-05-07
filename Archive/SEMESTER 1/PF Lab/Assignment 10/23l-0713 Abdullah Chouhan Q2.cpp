#include <iostream>
using namespace std;
void merge(char matrix1[][100], char matrix2[][100], char matrix3[][100]){
    for (int i = 0, j = 0; i < 6; i++, j++)
    {
        if (i == 3)
            j = 0;
        if (i < 3) {
            for (int k = 0; k < 100; k++)
                matrix3[i][k] = matrix1[j][k];
        }
        else {
            for (int k = 0; k < 100; k++)
                matrix3[i][k] = matrix2[j][k];  
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 100; j++){
            cout << matrix3[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    char mat1[][100] = {
        "This is first line with no space at start and no space at end",
        "This is second line with no space at start and no space at end",
        "third line with no space at start and no space at end"
    };
    char mat2[][100] = {
        "random text for mat2",
        "second line of random text for mat2",
        "third line of random text for mat2"
    };

    int mat1_size = sizeof(mat1);
    int mat2_size = sizeof(mat2);
    int m3_size = mat1_size + mat2_size;
    char mat3[m3_size/100][100];
    merge(mat1, mat2, mat3);

    return 0;
}