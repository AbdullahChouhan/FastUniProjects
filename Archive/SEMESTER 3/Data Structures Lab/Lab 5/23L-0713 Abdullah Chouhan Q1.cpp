#include <iostream>
template<typename T>
class Stack {
	private:
		class Node {
			public:
				T val;
				Node* below = nullptr;

				Node(T _val, Node* _below = nullptr) : val(_val), below(_below) {}
				static Node* Create(T _val, Node* _below = nullptr) {
					Node* temp = new Node(_val, _below);
					return temp;
				}
		};
		int capacity, size = 0;
		Node* top = nullptr;
	public:
		Stack(int _capacity) : capacity(_capacity) {}
		bool IsEmpty() const {
			return top == nullptr;
		}
		bool IsFull() const {
			return size >= capacity;
		}
		bool Push(T val) {
			if (IsFull())
				return false;
			top = Node::Create(val, top);
			size++;
			return true;
		}
		bool Pop() {
			if (IsEmpty()) {
				return false;
			}
			Node* temp = top;
			top = top->below;
			delete temp;
			size--;
			return true;
		}
		bool Top(T& _T) const {
			if (IsEmpty())
				return false;
			_T = top->val;
			return true;
		}
		T Top() const {
			if (IsEmpty())
				return T();
			return top->val;
		}
		~Stack() {
			while (top != nullptr) {
				Node* temp = top;
				top = top->below;
				delete temp;
			}
		}
};

int main() {
	int test = 0;
	"Creating a stack of size 9";
	Stack<int> test_stack(9);
	std::cout << "Is stack initialized as empty: ";
	if (test_stack.IsEmpty()) std::cout << "true"; else std::cout << "false"; std::cout << '\n';
	for (int i = 0; i < 9; i++) {
		test_stack.Push(i);
		test_stack.Top(test);
		std::cout << "Pushed value " << test << " into stack\n";
	}
	std::cout << "After insertions, is stack full: ";
	if (test_stack.IsFull()) std::cout << "true"; else std::cout << "false"; std::cout << '\n';
	for (int i = 0; i < 9; i++) {
		test_stack.Top(test);
		test_stack.Pop();
		std::cout << "Popped value " << test << " from stack\n";
	}
	std::cout << "After popping, is stack empty: ";
	if (test_stack.IsEmpty()) std::cout << "true"; else std::cout << "false"; std::cout << '\n';
	return 0;
}