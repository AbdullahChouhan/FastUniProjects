#include <iostream>
using namespace std;

void print(int shoothor1, int shoothor2, int shootver1, int shootver2)
{
    int j;
    char bound, middle;
    for (int i = 1; i <= 15; i++)
    {
        if (i == 15 || i == 1)
        {
            bound = '+';
            middle = '-';
        }
        else
        {
            bound = '|';
            middle = ' ';
        }
        cout << bound;
        for (j = 13; j >= 1; j-= 2)
        {
            if (j / shoothor1 == 1)
                cout << "<-";
            else
                cout << middle << middle;
        }
        if (i == 8)
        {
            cout << '+';
            j++;
        }
        for (j; j <= 26; j+= 2)
        {
            if (j / shoothor2 == 1)
                cout << "->";
            else
                cout << middle << middle;
        }
        cout << bound << '\n';
    }
}

int main()
{
    int firedir = -1, i, j, shootver1, shootver2, shoothor1, shoothor2;
    cout << "0: shoot right\n1: shoot left\n2 :shoot up\n3 :shoot bottom\n4 :shoot in all directions\nEnter your choice: ";
    cin >> firedir;
    switch (firedir)
    {
    case 0:
        shoothor2 = 15;
        break;
    case 1:
        shoothor1 = 13;
        break;
    case 2:
        shootver1 = 7;
        break;
    case 3:
        shootver2 = 9;
        break;
    case 4:
        shoothor2 = 15;
        shoothor1 = 13;
        shootver1 = 7;
        shootver2 = 9;
    default:
        break;
    }
    for (int c = 0; c < 13 / 2; c++)
    {
        
    }
    
    print(shoothor1, shoothor2, shootver1, shootver2);
    
    return 0;
}