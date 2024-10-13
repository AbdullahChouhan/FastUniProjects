#include "headers/DoublyLinkedList.hpp"

Node::Node(char data) : data(data), next(nullptr), prev(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

void DoublyLinkedList::insertAtHead(char data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    size++;
}

void DoublyLinkedList::deleteAtHead() {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete current;
    size--;
}

void DoublyLinkedList::recalcSize() {
    size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
}

int DoublyLinkedList::getSize() {
    return size;
}

Node* DoublyLinkedList::getNodeAt(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    if (index < size / 2) {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    } else {
        Node* current = tail;
        for (int i = size - 1; i > index; i--) {
            current = current->prev;
        }
        return current;
    }
}

void DoublyLinkedList::insertAfter(Node* prevNode, char data) {
    if (prevNode == nullptr) {
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    size++;
}

void DoublyLinkedList::insertAt(int index, char data) {
    if (index == 0) {
        insertAtHead(data);
    } else {
        Node* prevNode = getNodeAt(index - 1);
        insertAfter(prevNode, data);
    }
}

void DoublyLinkedList::insertAt(int index, DoublyLinkedList* list) {
    if (index == 0) {
        insertAtHead(list->head->data);
    } else {
        for (int i = 0; i < list->getSize(); i++) {
            insertAt(index + i, list->getNodeAt(i)->data);
        }
    }
}

void DoublyLinkedList::deleteAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) {
        return;
    }
    Node* toDelete = prevNode->next;
    prevNode->next = toDelete->next;
    if (toDelete->next != nullptr) {
        toDelete->next->prev = prevNode;
    } else {
        tail = prevNode;
    }
    delete toDelete;
    size--;
}

void DoublyLinkedList::deleteAt(int index) {
    if (index == 0) {
        deleteAtHead();
    } else {
        Node* prevNode = getNodeAt(index - 1);
        deleteAfter(prevNode);
    }
}

void DoublyLinkedList::deleteLength(int index, int length, bool forward) {
    if (index < 0 || index >= size || length <= 0) {
        return;
    }
    if (size - index < length) {
        length = size - index;
    }
    Node* current = getNodeAt(index);
    if (current == nullptr) {
        return;
    }
    Node* prevNode = current->prev;
    Node* nextNode = nullptr;

    if (forward) {
        for (int i = 0; i < length; i++) {
            nextNode = current->next;
            delete current;
            size--;
            current = nextNode;
            if (current == nullptr) {
                break;
            }
        }
        if (prevNode != nullptr) {
            prevNode->next = current;
        } else {
            head = current;
        }
        if (current != nullptr) {
            current->prev = prevNode;
        } else {
            tail = prevNode;
        }
    } else {
        for (int i = 0; i < length; i++) {
            nextNode = current->prev;
            delete current;
            size--;
            current = nextNode;
            if (current == nullptr) {
                break;
            }
        }
        if (current != nullptr) {
            current->next = nextNode;
        } else {
            tail = nextNode;
        }
        if (nextNode != nullptr) {
            nextNode->prev = current;
        } else {
            head = current;
        }
    }
    if (size == 0) {
        head = tail = nullptr;
    }
}

char DoublyLinkedList::operator[](int index) {
    return getNodeAt(index)->data;
}


DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::deleteParticular(Node* nptr) {
    if(nptr->prev)
        nptr->prev->next = nptr->next;
    if(nptr->next)
        nptr->next->prev = nptr->prev;
    delete nptr;
}

char* DoublyLinkedList::getNextLargest() {
	if (head == nullptr) return nullptr;

	int length = size;
	char* nextLargest = new char[length];

	Node* curr = head->next;
	for (int i = 0; i < length; i++) {
		Node* next = curr->next;
		char max = curr->data;
		while (next != nullptr) {
			if (next->data > max) {
				max = next->data;
			}
			next = next->next;
		}
		nextLargest[i] = max;
		curr = curr->next;
	}

	return nextLargest;
}

void DoublyLinkedList::removeNthFromEnd(int n) {
    if (n == size) {
        deleteAtHead();
        return;
    }
    if (n > size)
        return;
    Node* slow = head;
    Node* fast = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    deleteAfter(slow);
}
