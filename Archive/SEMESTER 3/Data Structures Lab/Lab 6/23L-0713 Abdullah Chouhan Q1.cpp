#include <iostream>

struct Node {
        int data;
        Node* next;
        Node* prev;
    public:
        Node() :next(nullptr), prev(nullptr), data(0) {}
        Node(int val, Node* nptr = nullptr, Node* pptr = nullptr) :data(val), next(nptr), prev(pptr) {}
        Node* createNode(int val, Node* nptr = nullptr, Node* pptr = nullptr) {
            Node* newNode = new Node(val, nptr, pptr);
            return newNode;
        }
};

class linkedList {
    private:
        Node* head, * tail;
        int size;
    public:
        linkedList()
        {
            head = tail = new Node;
            size = 0;
        }
        void insertAtHead(int val)
        {
            head->next = new Node(val, head->next);
            if (size == 0)
            {
                tail = head->next;
            }
            size++;
        }
        void insertAtTail(int val)
        {
            tail->next = new Node(val, tail->next);
            tail = tail->next;
            size++;
        }
        //void insertInOrder(T val)
        //{
        //    if (size == 0)
        //    {
        //        insertAtHead(val);
        //    }
        //    else if (val < head->next->data)
        //    {
        //        insertAtHead(val);
        //    }
        //    else if (val > tail->data)
        //    {
        //        insertAtTail(val);
        //    }
        //    else
        //    {
        //        Node* curr = head->next;
        //        Node* prev = head;
        //        while (curr->data < val)
        //        {
        //            prev = curr;
        //            curr = curr->next;
        //        }
        //        prev->next = new Node(val, curr);
        //        size++;
        //    }
        //}
        void deleteAtHead() {
            if (size > 0) {
                Node* temp = head->next;
                head->next = head->next->next;
                delete temp;
                if (size == 1)
                    tail = head;
                size--;
            }
        }
        void deleteAtTail() {
            if (size > 0) {
                Node* temp = head;
                while (temp->next != tail)
                    temp = temp->next;
                temp->next = nullptr;
                delete tail;
                tail = temp;
                size--;
            }
        }
        //void deleteParticular(const T& val)
        //{
        //    if (size > 0)
        //    {
        //        if (val == head->next->data)
        //        {
        //            deleteAtHead();
        //        }
        //        else if (val == tail->data)
        //        {
        //            deleteAtTail();
        //        }
        //        else
        //        {
        //            Node* curr = head->next;
        //            Node* prev = head;
        //            while (curr != nullptr && curr->data != val)
        //            {
        //                prev = curr;
        //                curr = curr->next;
        //            }
        //            if (curr != nullptr)
        //            {
        //                prev->next = curr->next;
        //                delete curr;
        //                size--;
        //            }
        //        }
        //    }
        //}
        void print()
        {
            Node* temp = head->next;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        class Iterator
        {
            private:
                linkedList* list;
                Node* ptr;
            public:
                Iterator(Node* p, linkedList* l = nullptr) : list(l), ptr(p) {}
                Iterator& operator++() {
                    ptr = ptr->next;
                    return *this;
                }
                Iterator& operator++(int) {
                    ptr = ptr->next;
                    return *this;
                }
                int operator &() {
                    return ptr->data;
                }
                bool operator != (const Iterator& other) const {
                    return !(ptr == other.ptr);
                }
                bool operator == (const Iterator& other) const {
                    return ptr == other.ptr;
                }
                Node* operator*() {
                    return ptr;
                }
                void delCurPtr() {
                    if (ptr != nullptr) {
                        if (ptr->next != nullptr) {
                            ptr->data = ptr->next->data;
                            Node* temp = ptr->next;
                            ptr->next = ptr->next->next;
                            if (temp->next == nullptr)
                                list->tail = ptr;
                            delete temp;
                            list->size--;
                        }
                        else {
                            list->deleteAtTail();
                            ptr = list->tail;
                        }
                    }
                }
        };
        Iterator begin() {
            return Iterator(head->next, this);
        }
        Iterator end() {
            return Iterator(tail->next, this);
        }
        ~linkedList()
        {
            Node* curr = head;
            Node* prev;
            while (curr != nullptr)
            {
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
};

void deleteSubSequence(linkedList &list) {
    linkedList::Iterator it = list.begin();
    while (it != list.end()) {
        if ((*it)->next != nullptr) {
            if (&it == 1 && (*it)->next->data == 0) {
                it.delCurPtr();
                while (&it == 0) {
                    it.delCurPtr();
                }
            }
            else {
                it++;
            }
        }
        else if (&it == 0) {
            it.delCurPtr();
        }
        else {
            it++;
        }
    }
}
int main() {
   linkedList list;
   list.insertAtTail(1);
   list.insertAtTail(0);
   list.insertAtTail(0);
   list.insertAtTail(1);
   list.insertAtTail(1);
   list.insertAtTail(0);
   std::cout << "\n\nBefore deletion: ";
   list.print();
   std::cout << "\nAfter deletion: ";
   deleteSubSequence(list);
   list.print();
}