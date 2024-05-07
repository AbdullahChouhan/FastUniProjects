#include <iostream>

template <typename T>
class Pair {
    private:
        T Array[2];
    public:
        Pair() {}
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
        friend std::ostream& operator<<(std::ostream& cout, const Pair<T>& p) {
            cout << p.Array[0] << " " << p.Array[1];
            return cout;
        }
};
template <typename T>
T Pair<T>::GetMin() {
    if (Array[0] < Array[1])
        return Array[0];
    else
        return Array[1];
}

template <class T, int N>
class Sequence {
    private:
        T memblock[N];
    public:
        void setMember(int x, T y);
        T getMember(int x);
};
template <class T, int N>
void Sequence<T, N>::setMember(int x, T y) {
    memblock[x] = y;
}
template <class T, int N>
T Sequence<T, N>::getMember(int x) {
    return memblock[x];
}

int main ()
{
    Pair <double> y (2.23,3.45);
    Sequence <Pair<double>,5> myPairs;
    myPairs.setMember (0,y);
    std::cout << myPairs.getMember(0) << '\n';
}