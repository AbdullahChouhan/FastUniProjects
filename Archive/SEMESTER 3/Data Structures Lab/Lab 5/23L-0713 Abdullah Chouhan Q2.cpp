#include <iostream>
template<typename T>
class Stack {
	private:
		T* stack;
		int size;
		int top = -1;
	public:
		Stack(int size = 10) : size(size) {
			stack = new T[size];
		}
		bool Push(T val) {
			if (top >= size - 1)
				return false;
			stack[++top] = val;
		}
		bool Pop() {
			if (top < 0) {
				return false;
				std::cout << "\nStack's empty!\n";
			}
			top--;
			return true;
		}
		bool Top(T& _T) {
			if (top < 0)
				return false;
			_T = stack[top];
			return true;
		}
		bool IsEmpty() {
			if (top < 0)
				return true;
			else
				return false;
		}
		bool IsFull() {
			if (top >= size - 1)
				return true;
			else
				return false;
		}
		~Stack() {
			delete[] stack;
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
		std::cout << "Popped value " << test << " from stack\n";
		test_stack.Pop();
	}
	std::cout << "After popping, is stack empty: ";
	if (test_stack.IsEmpty()) std::cout << "true"; else std::cout << "false"; std::cout << '\n';
	return 0;
}