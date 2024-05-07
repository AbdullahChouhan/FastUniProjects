#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream myfile;
    myfile.open("D:/alex.txt",ios::app);
    if (myfile.is_open())
    {
        myfile << "Who the hell is Steve Jobs";
        myfile << "No way";
        myfile.close(); //nerd
    }
}