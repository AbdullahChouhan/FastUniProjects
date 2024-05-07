#include <iostream>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;

    cout << "Enter first point's coordinates\n";
    cin >> x1 >> y1;
    cout << "Enter second point's coordinates\n";
    cin >> x2 >> y2;
    cout << "Enter third point's coordinates\n";
    cin >> x3 >> y3;

    if ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0)
        cout << "The points are collinear!";
    else 
        cout << "The points are not collinear!";
    return 0;
}