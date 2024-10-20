#include <iostream>

template<typename T>
class Queue
{
	private:
		struct Node
		{
			T data;
			Node* next;
			Node(T val, Node* nptr = nullptr) : data(val), next(nptr) {}
		};
		Node* head, * tail;
		int size, currSize;
		
	public:
		Queue(int _size = 10) :head(nullptr), tail(nullptr), size(_size), currSize(0) {}
		
        bool isFull() {
            return currSize == size;
        }
        
        bool isEmpty() {
            return currSize == 0;
        }
		
		void Enqueue(const T val)
		{
			if (IsFull()) {
				return;
			}
			if (head == nullptr) {
				Node* n = new Node(val);
				if (head == nullptr) {
					head = n;
					tail = n;
					return;
				}
				n->next = head;
				head = n;
				return;
			}
			Node* n = new Node(val);
			tail->next = n;
			tail = tail->next;
			currSize++;
		}
		
		void Dequeue() {
			if (IsEmpty()) {
				return;
			}
			if (head == nullptr)
				return;
			Node* temp = head;
			head = head->next;
			delete temp;
			currSize--;
		}
		
		void print() {
			Node* temp = head;
			while (temp != nullptr) {
				std::cout << temp->data << " ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
};

int main() {
	Queue<int> Queue1;
	Queue1.Enqueue(3);
	Queue1.Enqueue(7);
	Queue1.Enqueue(9);
	Queue1.Enqueue(1);
	Queue1.Enqueue(0);

	std::cout << "\nQueue1 is: ";
	Queue1.print();
	
	Queue1.Dequeue();
	std::cout << "After Dequeue, Queue1 is: ";
	Queue1.print();

	return 0;	
}