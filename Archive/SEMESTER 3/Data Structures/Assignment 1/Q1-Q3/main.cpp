#include <iostream>

#include "headers/DoublyLinkedList.hpp"

int main() {
    DoublyLinkedList dll;

    // e -> d -> b -> c -> a
    dll.insertAtHead('a');
    dll.insertAtHead('c');
    dll.insertAtHead('b');
    dll.insertAtHead('d');
    dll.insertAtHead('e');

    //getNextLargest
    char* nextLargest = dll.getNextLargestNodes();
    std::cout << "Next largest: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << nextLargest[i] << " ";
    }
    std::cout << std::endl;
    delete[] nextLargest;

    //removeNthFromEnd
    dll.removeNthFromEnd(2);
    std::cout << "After removing 2nd node from end: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << dll[i] << " ";
    }
    std::cout << std::endl;

    //deleteParticular
    Node* nodeToDelete = dll.getNodeAt(1);
    dll.deleteParticular(nodeToDelete);
    std::cout << "After deleting particular node: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << dll[i] << " ";
    }
    std::cout << std::endl;
    dll.~DoublyLinkedList();
}