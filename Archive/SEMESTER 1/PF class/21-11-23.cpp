#include <iostream>
using namespace std;

int main()
{
    int sum = 0, array[3][3] = {1,2,3,4,5,6,7,8,9};
    cout << "1";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += array[i][j];
            cout << " + " << array[i][j];
        }
    }
    cout << " = " << sum;
    return 0;
}