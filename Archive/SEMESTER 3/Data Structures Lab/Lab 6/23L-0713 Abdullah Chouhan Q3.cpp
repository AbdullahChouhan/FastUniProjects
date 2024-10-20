#include<iostream>

class Queue
{
    private:
        int *arr, rear, front, size, currSize;
        
    public:
        Queue(int _capacity) : arr(new int[_capacity]), front(0), rear(-1), size(_capacity), currSize(0) {}
        
        bool isFull() {
            return currSize == size;
        }
        
        bool isEmpty() {
            return currSize == 0;
        }
        
        void Enqueue(int value){
            if (isFull()) {
                std::cout <<"The Queue is full\n";
                return;
            }
            arr[(++rear)%size] = value;
            currSize++;
        }
        
        void Dequeue(){
            if (isEmpty()) {
                std::cout <<"The Queue is empty";
                return;
            }
            front++;
            currSize--;
            if (isEmpty()) {
                front = 0;
                rear = -1;
            }
        }
        
        void Print(){
            if (isEmpty()) {
                std::cout << "The Queue is empty";
                return;
            }
            for (int i = front; i <= rear; i++) {
                std::cout << arr[(i)%size] << " ";
            }
            std::cout << std::endl;
        }
        
        ~Queue(){}
};


int main() {
    Queue Queue1(5);

	Queue1.Enqueue(3);
	Queue1.Enqueue(7);
	Queue1.Enqueue(9);
	Queue1.Enqueue(1);
	Queue1.Enqueue(0);

    std::cout << "\nQueue1 is: ";
    Queue1.Print();

    Queue1.Dequeue() ;
    std::cout << "After Dequeue, Queue1 is: ";
    Queue1.Print();

    Queue1.Enqueue(10);
    std::cout << "After Enqueue, Queue1 is: ";
    Queue1.Print();

    return 0;
}