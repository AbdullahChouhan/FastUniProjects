#include <iostream>

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
    Sequence <int,5> myints;
    Sequence <double,5> myfloats;
    myints.setMember (0,100);
    myfloats.setMember (3,3.1416);
    std::cout << myints.getMember(0) << '\n';
    std::cout << myfloats.getMember(3);
    return 0;
}
