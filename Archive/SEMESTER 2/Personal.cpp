#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float col[18];
    cout << "\nEnter values\n";
    for (int i = 0; i < 18; i++)
        cin >> col[i];

    while (col[0] != -1.f)
    {
        for (int i = 0; i < 18; i++) {
            if ((i + 3) % 3 == 0)
                cout << "Vector3f(";
            cout << fixed << setprecision(5) << col[i] / 255.f << 'f';
            if ((i + 1) % 3 == 0) {
                cout << ")";
                if (i == 17)
                    cout << "};";
                else
                    cout << ", ";
            }
            else
                cout << ", ";
        }
        cout << "\nEnter values\n";
        for (int i = 0; i < 18; i++)
            cin >> col[i];
    }
}

