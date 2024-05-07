#include <iostream>

template <typename T>
class Pair {
    private:
        T Array[2];
    public:
        Pair(T x, T y) {
            Array[0] = x;
            Array[1] = y;
        }
        T GetMax() {
            if (Array[0] > Array[1])
                return Array[0];
            else
                return Array[1];
        }
        T GetMin();
};
template <typename T>
T Pair<T>::GetMin() {
    if (Array[0] < Array[1])
        return Array[0];
    else
        return Array[1];
}

int main() {
    Pair <double> myobject (1.012, 1.01234);
    std::cout << myobject.GetMax();
    return 0;
}