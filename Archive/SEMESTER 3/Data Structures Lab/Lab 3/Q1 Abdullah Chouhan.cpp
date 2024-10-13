#include <iostream>
#include <cstring>

template <typename T>
struct Node {
    public:
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        SinglyLinkedList() : head(nullptr), tail(nullptr) {}
        SinglyLinkedList(T data) : head(new Node<T>(data)), tail(head) {}
        void insertAtHead(T data) {
            Node<T> *newNode = new Node<T>(data);
            if (head == nullptr)
                tail = newNode;
            else
                newNode->next = head;
            head = newNode;
        }
        void insertAtTail(T data) {
            Node<T> *newNode = new Node<T>(data);
            if (head == nullptr)
                head = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }
        void printForward() {
            Node<T> *current = head;
            while (1) {
                std::cout << current->data;
                current = current->next;
                if (current == nullptr)
                    break;
                else
                    std::cout << " -> ";
            }
            std::cout << std::endl;
        }
        void deleteFromHead() {
            if (head == nullptr)
                return;
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        void deleteFromTail() {
            if (head == nullptr)
                return;
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node<T> *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            current->next = nullptr;
            tail = current;
        }
        int Size() const {
            int count = 0;
            Node<T> *current = head;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }
        int getMiddleConst() const {
            if (head == nullptr)
                return -1;
            Node<T> *current = head;
            int middle = Size() / 2;
            current = head;
            for (int i = 0; i < middle; i++) {
                current = current->next;
            }
            return current->data;
        }
        bool isEmpty() {
            return head == nullptr;
        }
        void insertAfter(T val, T key) {
            if (head != nullptr) {
                Node<T> *newNode = new Node<T>(val);
                Node<T> *current = head;
                while (current != nullptr) {
                    if (current->data == key) {
                        newNode->next = current->next;
                        current->next = newNode;
                        return;
                    }
                    current = current->next;
                }
            }
            insertAtTail(val);
        }
        void insertBefore(T val, T key) {
            if (head != nullptr) {
                if (head->data == key) {
                    insertAtHead(val);
                    return;
                }
                Node<T> *newNode = new Node<T>(val);
                Node<T> *current = head;
                while (current->next != nullptr) {
                    if (current->next->data == key) {
                        newNode->next = current->next;
                        current->next = newNode;
                        return;
                    }
                    current = current->next;
                }
            }
            insertAtTail(val);
        }
        int getMax() const {
            if (head == nullptr)
                return -1;
            int max = head->data;
            Node<T> *current = head;
            while (current != nullptr) {
                if (current->data > max)
                    max = current->data;
                current = current->next;
            }
            return max;
        }
        int getMin() const {
            if (head == nullptr)
                return -1;
            int min = head->data;
            Node<T> *current = head;
            while (current != nullptr) {
                if (current->data < min)
                    min = current->data;
                current = current->next;
            }
            return min;
        }
        int getAverage() const {
            if (head == nullptr)
                return -1;
            int sum = head->data;
            Node<T> *current = head;
            while (current != nullptr) {
                sum += current->data;
                current = current->next;
            }
            return sum / Size();
        }
        bool Swap(int l, int r) {
            if (head == nullptr || head->next == nullptr)
                return false;
            int size = Size();
            if (l > size || r > size || l < 0 || r < 0)
                return false;
            if (l == r)
                return true;
            Node<T> *left = head;
            Node<T> *right = head;
            int i = 0;
            if (r > l) {
                int temp = l;
                l = r;
                r = temp;
            }
            for (i = 0; i < r - 1; i++) {
                left = left->next;
            }
            right = left;
            for (i; i < l - 1; i++) {
                right = right->next;
            }
            Node<T> *temp = nullptr;
            temp = left->next;
            left->next = right->next;
            right->next = temp;
            temp = left->next->next;
            left->next->next = right->next->next;
            right->next->next = temp;
            return true;
        }
        int totalCharCount() {
            if (head == nullptr)
                return -1;
            std::string s = "";
            Node<T> *current = head;
            while (current != nullptr) {
                s = s + to_string(current->data);
                current = current->next;
            }
            return s.length();
        }
        void split(SinglyLinkedList<T> &list1, SinglyLinkedList<T> &list2) {
            if (head == nullptr)
                return;
            Node<T> *current = head;
            int max = Size(), middle = max / 2, i = 0;
            for (i = 0; i < middle; i++) {
                list1.insertAtTail(current->data);
                current = current->next;
            }
            list2.insertAtTail(current->data);
            for (i; i < max - 1; i++) {
                current = current->next;
                list2.insertAtTail(current->data);
            }
        }
        void merge(SinglyLinkedList<T> &firstHalf, SinglyLinkedList<T> &secondHalf) {
            if (firstHalf.head == nullptr || secondHalf.head == nullptr)
                return;
            this->~SinglyLinkedList();
            Node<T> *current = firstHalf.head;
            while (current != nullptr) {
                insertAtTail(current->data);
                current = current->next;
            }
            current = secondHalf.head;
            while (current != nullptr) {
                insertAtTail(current->data);
                current = current->next;
            }
        }
        ~SinglyLinkedList() {
            Node<T> *current = head;
            while (current != nullptr) {
                Node<T> *temp = current;
                current = current->next;
                delete temp;
            }
        }
};

int main() {
    SinglyLinkedList<int> list(10);

    std::cout << "List: ";
    list.printForward();

    list.insertAtTail(2);
    std::cout << "\nList after inserting 2 at tail: ";
    list.printForward();

    list.insertAtHead(7);
    std::cout << "\nList after inserting 7 at head: ";
    list.printForward();

    list.insertAfter(100, 10);
    std::cout << "\nList after inserting 100 after 10: ";
    list.printForward();

    list.insertAfter(110, 20);
    std::cout << "\nList after inserting 110 after 20 (it does not exist so appended at tail): ";
    list.printForward();

    list.insertBefore(80, 2);
    std::cout << "\nList after inserting 80 before 2: ";
    list.printForward();

    list.insertBefore(130, 35);
    std::cout << "\nList after inserting 130 before 35 (it does not exist so appended at tail): ";
    list.printForward();

    list.Swap(3, 5);
    std::cout << "\nList after swapping the 4th and 5th index: ";
    list.printForward();

    std::cout << "\nMaximum in list: " << list.getMax();
    std::cout << "\nMinimum in list: " << list.getMin();
    std::cout << "\nMiddle in list: " << list.getMiddleConst();
    std::cout << "\nAverage in list: " << list.getAverage();

    SinglyLinkedList<int> l1, l2;

    list.split(l1, l2);
    std::cout << "\n\nList after splitting into two halves:\n";
    std::cout << "First half: ";
    l1.printForward();
    std::cout << "Second half: ";
    l2.printForward();

    list.merge(l1, l2);
    std::cout << "\nAfter merging the two lists into one:\n";
    list.printForward();
}