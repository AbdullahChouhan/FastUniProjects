#include <iostream>
using namespace std;

int random_generator()
{
    srand(time(0));
    return 1 + rand() % 20;
}

void multiply_arrays(int array1[], int array2[], int (&array3)[], int m1, int n1, int m2, int n2)
{
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            for (int k = 0; k < n1; k++)
                array3[i,j] += array1[i,k] * array2[k,i];
        }
    }
}

int main()
{
    int m1,n1,m2,n2;
    cout << "Enter rows for array 1: ";
    cin >> m1;
    cout << "Enter columns for array 1: ";
    cin >> n1;
    cout << "Enter rows for array 2: ";
    cin >> m2;
    cout << "Enter columns for array 2: ";
    cin >> n2;

    int array1[m1][n1], array2[m2][n2];
    cout << "Entering random values into arrays...\n";
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
            array1[i][j] = random_generator();
    }
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
            array2[i][j] = random_generator();
    }
    cout << "Attempting multiplication...\n";
    if (n1 == m2)
    {
        int array3[m1][n2];
        multiply_arrays(array1[2][3], array2[][3], array3[][3], m1, n1, m2, n2);
        for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n2; j++)
                    cout << array3[i,j] << " ";
                cout << '\n';
            }
    }
    else 
        cout << "Invalid!";
}