#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int AGE;
    string NAME, CITY, COLLEGE, PROFESSION, ANIMAL, PETNAME;
    cout << "Enter your name: ";
    cin >> NAME;
    cout << "Enter your age: ";
    cin >> AGE;
    cout << "Name a city: ";
    cin >> CITY;
    cout << "Name a college: ";
    cin >> COLLEGE;
    cout << "Name a profession: ";
    cin >> PROFESSION;
    cout << "Name a type of animal: ";
    cin >> ANIMAL;
    cout << "Name a pet's name: ";
    cin >> PETNAME;
    cout << "There once was a person named " << NAME << " who lived in " << CITY << ". At the age of " << AGE << ", " << NAME << " went to college at " << COLLEGE << ". " << NAME << " graduated and went to work as a " << PROFESSION << ". Then, " << NAME << " adopted ";
    if (ANIMAL[0] == 'A' || ANIMAL[0] == 'E' || ANIMAL[0] == 'I' || ANIMAL[0] == 'O' || ANIMAL[0] == 'U' || ANIMAL[0] == 'a' || ANIMAL[0] == 'e' || ANIMAL[0] == 'i' || ANIMAL[0] == 'o' || ANIMAL[0] == 'u')
        cout << "an ";
    else
        cout << "a ";
    cout << ANIMAL << " named " << PETNAME << ". They both lived happily ever after!";
    return 0;
}