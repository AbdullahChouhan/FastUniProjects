#include <iostream>

template <typename T>
class OrderedDoubly {
    private:
        class Node {
            public:
                T data;
                Node *prev;
                Node *next;
                static Node* create(T data, Node* prev = nullptr, Node* next = nullptr) {
                    Node* newNode = new Node();
                    newNode->data = data;
                    newNode->next = next;
                    newNode->prev = prev;
                    return newNode;
                }
        };
        Node* head;
        Node* tail;
        unsigned int size;
        class Iterator {
            private:
                Node* current;
            public:
                Iterator(Node* current) : current(current) {}
                Iterator& operator++() {
                    current = current->next;
                    return *this;
                }
                Iterator operator++(int) {
                    Iterator temp = *this;
                    current = current->next;
                    return temp;
                }
                Iterator& operator--() {
                    current = current->prev;
                    return *this;
                }
                Iterator operator--(int) {
                    Iterator temp = *this;
                    current = current->prev;
                    return temp;
                }
                T& operator*() {
                    return current->data;
                }
                bool operator==(const Iterator& other) const {
                    return current == other.current;
                }
                bool operator!=(const Iterator& other) const {
                    return current != other.current;
                }
        };

    public:
        OrderedDoubly<T>() : head(nullptr), tail(nullptr), size(0) {}
        Iterator begin() const {
            return Iterator(head);
        }
        Iterator end() const {
            return Iterator(nullptr);
        }
        void orderedInsert(T data) {
            Node* newNode = Node::create(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr && current->data < data) {
                    current = current->next;
                }
                if (current->data < data) {
                    if (current == tail) {
                        current->next = newNode;
                        newNode->prev = current;
                        tail = newNode;
                    } else {
                        std::cout << "Not in order\n";
                    }
                } else {
                    if (current->prev == nullptr) {
                        newNode->next = current;
                        head = newNode;
                    } else {
                        newNode->next = current;
                        newNode->prev = current->prev;
                        current->prev->next = newNode;
                        current->prev = newNode;
                    }
                }
            }
            size++;
        }
        void printForward() const {
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data;
                if (current->next != nullptr) {
                    std::cout << "->";
                }
                current = current->next;
            }
            std::cout << std::endl;
        }
        void printBackward() const {
            Node* current = tail;
            while (current != nullptr) {
                std::cout << current->data;
                if (current->prev != nullptr) {
                    std::cout << "->";
                }
                current = current->prev;
            }
            std::cout << std::endl;
        }
        bool search(T data) const {
            bool searchforw = true;
            Node* current = head;
            if (abs(current->data - data) > abs(tail->data - data)) {
                current = tail;
                searchforw = false;
            }
            for (int i = 0; i < size / 2 && current != nullptr; i++) { // Accessing n/2 only
                if (current->data == data) {
                    return true;
                }
                if (searchforw) {
                    current = current->next;
                } else {
                    current = current->prev;
                }
            }
            return false;
        }
        void erase(T data) {
            bool searchforw = true;
            Node* current = head;
            if (abs(current->data - data) > abs(tail->data - data)) {
                current = tail;
                searchforw = false;
            }
            while (current != nullptr) {
                if (current->data == data) {
                    if (searchforw) {
                        current->next->prev = current->prev;
                        current->prev->next = current->next;
                    } else {
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                    }
                    delete current;
                    size--;
                    return;
                }
                if (searchforw) {
                    current = current->next;
                } else {
                    current = current->prev;
                }
            }
        }
        ~OrderedDoubly() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }   
};

template <typename T>
void printList(const OrderedDoubly<T>& list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void unionList(const OrderedDoubly<T>& a, const OrderedDoubly<T>& b, OrderedDoubly<T>& c) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        c.orderedInsert(*it);
    }
    for (auto it = b.begin(); it != b.end(); ++it) {
        c.orderedInsert(*it);
    }
}

template <typename T>
void intersectionList(const OrderedDoubly<T>& a, const OrderedDoubly<T>& b, OrderedDoubly<T>& c) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (b.search(*it)) {
            c.orderedInsert(*it);
        }
    }
}

template <typename T>
void differenceList(const OrderedDoubly<T>& a, const OrderedDoubly<T>& b, OrderedDoubly<T>& c) {
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (!b.search(*it)) {
            c.orderedInsert(*it);
        }
    }
}

template <typename T>
void bubblesortList(OrderedDoubly<T>& list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        for (auto jt = it; jt != list.end(); ++jt) {
            if (*it < *jt) {
                T temp = *it;
                *it = *jt;
                *jt = temp;
            }
        }
    }
}


int main() {
    std::cout << "Testing orderedInsert + printList...\n";
    {
        OrderedDoubly<int> a;
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.orderedInsert(5);
        a.orderedInsert(6);
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(7);
        a.orderedInsert(8);
        printList(a);
        std::cout << "\n";
        std::cout << std::endl;
    }

    std::cout << "Testing search...\n";
    {
        OrderedDoubly<int> a;
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.orderedInsert(5);
        a.orderedInsert(6);
        a.orderedInsert(7);
        a.orderedInsert(8);
        if (!a.search(5)) {
            std::cout << "Not found 5" << std::endl;
        }
        else
            std::cout << "Found 5" << std::endl;
        
        if (!a.search(10)) {
            std::cout << "Not found 10" << std::endl;
        }
        else
            std::cout << "Found 10" << std::endl;
    }

    std::cout << "Testing delete... + printforward + printbackward\n";
    {
        OrderedDoubly<int> a;
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.orderedInsert(5);
        a.orderedInsert(6);
        a.orderedInsert(7);
        a.orderedInsert(8);
        a.printForward();
        std::cout << "Before: \n";
        a.erase(5);
        a.printForward();
        std::cout << "After deleting 5\n";
        a.erase(10);
        a.printBackward();
        std::cout << "After deleting 10 and printing backward\n";
    }

    std::cout << "Testing union...\n";
    {
        OrderedDoubly<int> a, b, c;
        std::cout << "a: \n";
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.printForward();
        std::cout << "\nb: \n";
        b.orderedInsert(3);
        b.orderedInsert(4);
        b.orderedInsert(5);
        b.orderedInsert(6);
        b.printForward();
        std::cout << "\nUnion: \n";
        unionList(a, b, c);
        c.printForward();
        std::cout << "\n";
    }

    std::cout << "Testing intersection...\n";
    {
        OrderedDoubly<int> a, b, c;
        std::cout << "a: \n";
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.printForward();
        std::cout << "\nb: \n";
        b.orderedInsert(3);
        b.orderedInsert(4);
        b.orderedInsert(5);
        b.orderedInsert(6);
        b.printForward();
        std::cout << "\nIntersection: \n";
        intersectionList(a, b, c);
        c.printForward();
        std::cout << "\n";
    }

    std::cout << "Testing difference...\n";
    {
        OrderedDoubly<int> a, b, c;
        std::cout << "a: \n";
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.printForward();
        std::cout << "\nb: \n";
        b.orderedInsert(3);
        b.orderedInsert(4);
        b.orderedInsert(5);
        b.orderedInsert(6);
        b.printForward();
        std::cout << "\nDifference: \n";
        differenceList(a, b, c);
        c.printForward();
        std::cout << "\n";
    }

    std::cout << "Testing bubblesort...\n";
    {
        OrderedDoubly<int> a;
        std::cout << "Before: \n";
        a.orderedInsert(1);
        a.orderedInsert(2);
        a.orderedInsert(3);
        a.orderedInsert(4);
        a.orderedInsert(5);
        a.orderedInsert(6);
        a.orderedInsert(7);
        a.orderedInsert(8);
        a.printForward();
        std::cout << "\nAfter:\n";
        bubblesortList(a);
        a.printForward();
        std::cout << "\n";
    }

    return 0;
}