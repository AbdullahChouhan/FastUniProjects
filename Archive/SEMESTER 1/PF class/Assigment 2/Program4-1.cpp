#include <iostream>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, m12, m23;

    cout << "Enter first point's coordinates\n";
    cin >> x1 >> y1;
    cout << "Enter second point's coordinates\n";
    cin >> x2 >> y2;
    cout << "Enter third point's coordinates\n";
    cin >> x3 >> y3;

    m12 = (y2 - y1) / (x2 - x1);
    m23 - (y3 -y2) / (x3 - x2);

    if (m12 == m23)
        cout << "The points are collinear!";
    else 
        cout << "The points are not collinear!";
    return 0;
}