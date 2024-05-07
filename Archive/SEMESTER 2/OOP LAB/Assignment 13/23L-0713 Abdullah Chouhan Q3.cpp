#include <iostream>

template <class T>
class Container {
    private:
        T data;
    public:
        Container(T data);
        T increase();
        T uppercase();
};

template <class T>
Container<T>::Container(T data) {
    this->data = data;
}
template <class T>
T Container<T>::increase() {
    return data + 1;
}
template <class T>
T Container<T>::uppercase() {
    if (data >= 'a' && data <= 'z') {
        return data - 32;
    } else {
        return data;
    }
}

int main() {
    Container<int> myint (7);
    Container<char> mychar ('j');
    std::cout << myint.increase() << '\n';
    std::cout << mychar.uppercase();
    return 0;
}