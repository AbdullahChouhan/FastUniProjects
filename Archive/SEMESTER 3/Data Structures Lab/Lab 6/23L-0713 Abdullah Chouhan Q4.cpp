#include <iostream>

template<typename T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node(T val, Node* nptr = nullptr) : data(val), next(nptr) {}
        };
        Node* head;
        int currentsize, size;

    public:
        Stack(int _size = 100) :head(nullptr), currentsize(0), size(_size) {}

        bool push(T val) {
            if (isFull())
                return false;

            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                return false;
            }
            newNode->next = head;
            head = newNode;
            currentsize++;
            return true;
        }

        T Top() {
            T val;
            if (head == nullptr)
                return false;
            val = head->data;
            return val;
        }

        bool pop()
        {
            if (head == nullptr && isEmpty())
                return false;
            Node* temp = head;
            if (head->next)
                head = head->next;
            else
                head = nullptr;
            delete temp;
            currentsize--;
            return true;
        }

        bool isEmpty() {
            return (head == nullptr && currentsize != size);
        }
        
        bool isFull() {
            return currentsize == size;
        }
        
        ~Stack() {
            for (int i = 0; i < currentsize; i++) {
                pop();
            }
        }
};

class Queue
{
    private:
        Stack<int> s1, s2, s3;
        int size, current;
        void s1tos2() {
            while (!s1.isEmpty()) {
                s2.push(s1.Top());
                s1.pop();
            }
        }
        
        void s2tos3() {
            while (!s3.isEmpty()) {
                s2.push(s3.Top());
                s3.pop();
            }
        }

    public:
        Queue(int _size) : size(_size), current(0) {}
        
        bool isFull() {
            return current == size;
        }
        
        bool isEmpty() {
            return current == 0;
        }
        
        void Enqueue(int a) {
            if (isFull()) {
                std::cout << "The Queue is full\n";
                return;
            }
            s1.push(a);
            current++;
        }
        
        void Dequeue() {
            if (s2.isEmpty()) {
                if (s1.isEmpty()) {
                    std::cout << "The Queue is empty\n" ;
                    return;
                }
                s1tos2();
            }
            s2.pop();
            current--;
        }
        
        void print() {
            if (isEmpty()) {
                std::cout << "The Queue is empty.\n" ;
                return;
            }
            while (!s2.isEmpty()) {
                std::cout << s2.Top() << " ";
                s3.push(s2.Top());
                s2.pop();
            }
            if (!s1.isEmpty())
            {
                Stack<int> revStack;

                while (!s1.isEmpty()) {
                    revStack.push(s1.Top());
                    s1.pop();
                }
                while (!revStack.isEmpty()) {
                    std::cout << revStack.Top() << " ";
                    s3.push(revStack.Top());
                    revStack.pop();
                }
            }
            s2tos3();
            std::cout << '\n';
        }
        
        ~Queue() {}
};

int main() {
    Queue Queue1(5);

	Queue1.Enqueue(3);
	Queue1.Enqueue(7);
	Queue1.Enqueue(9);
	Queue1.Enqueue(1);
	Queue1.Enqueue(0);

    std::cout << "\nQueue1 is: ";
    Queue1.print();

    Queue1.Dequeue() ;
    std::cout << "After Dequeue, Queue1 is: ";
    Queue1.print();

    Queue1.Enqueue(10);
    std::cout << "After Enqueue, Queue1 is: ";
    Queue1.print();

    return 0;
}