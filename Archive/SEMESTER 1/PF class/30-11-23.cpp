#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;
    ifstream myfile("D:/alex.txt");

    if (myfile)
    {
        while (!myfile.eof())
        {
            myfile >> line;
            cout << line << '\n';
        }
    }
    else
        cout << "File not open";
    myfile.close();
}