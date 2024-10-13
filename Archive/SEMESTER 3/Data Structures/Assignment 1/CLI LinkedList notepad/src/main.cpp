#include "headers/App.hpp"

int main() {
    DoublyLinkedList dll;

    // Insert some data
    dll.insertAtHead('a');
    dll.insertAtHead('c');
    dll.insertAtHead('b');
    dll.insertAtHead('d');
    dll.insertAtHead('e');

    // Test getNextLargest
    char* nextLargest = dll.getNextLargest();
    std::cout << "Next largest: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << nextLargest[i] << " ";
    }
    std::cout << std::endl;
    delete[] nextLargest;

    // Test removeNthFromEnd
    dll.removeNthFromEnd(2);
    std::cout << "After removing 2nd node from end: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << dll[i] << " ";
    }
    std::cout << std::endl;

    // Test deleteParticular
    Node* nodeToDelete = dll.getNodeAt(1);
    dll.deleteParticular(nodeToDelete);
    std::cout << "After deleting particular node: ";
    for (int i = 0; i < dll.getSize(); i++) {
        std::cout << dll[i] << " ";
    }
    std::cout << std::endl;

    return 0;

    App::Run();
    return 0;
}