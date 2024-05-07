#include <iostream>

template <typename T, typename U = char> T GetMax(T x, U y) {
    if (x > y)
        return x;
    else {
        return y;
    }
}

template <typename T, typename U> T GetMin(T x, U y) {
    if (x < y)
        return x;
    else {
        return y;
    }
}

int main() {
    char i= 'Z';
    int j=6, k;
    long l=10, m=5, n;
    k=GetMax(i,m);
    n=GetMin(j,l);
    std::cout << k << "\n";
    std::cout << n;
    return 0;
}