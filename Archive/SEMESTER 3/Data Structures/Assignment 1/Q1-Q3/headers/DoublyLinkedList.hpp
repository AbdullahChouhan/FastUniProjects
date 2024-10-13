#pragma once

struct Node {
    public:
        char data;
        Node* next;
        Node* prev;
        Node(char data);
};

class DoublyLinkedList {
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList();
        void insertAtHead(char data);
        void deleteAtHead();
        void recalcSize();
        int getSize();
        Node* getNodeAt(int index);
        void insertAfter(Node* prevNode, char data);
        void insertAt(int index, char data);
        void insertAt(int index, DoublyLinkedList* list);
        void deleteAfter(Node* prevNode);
        void deleteAt(int index);
        void deleteLength(int index, int length, bool forward);
        char operator[](int index);
        void deleteParticular(Node * nptr);
        char* getNextLargestNodes();
        void removeNthFromEnd(int n);
        void deleteNode(char val);
        ~DoublyLinkedList();
};