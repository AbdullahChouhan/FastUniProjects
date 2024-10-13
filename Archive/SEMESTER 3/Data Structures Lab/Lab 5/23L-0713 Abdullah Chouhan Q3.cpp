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

class expressionEval {
	private:
		static int strLen(const char* str) {
			const char* ptr = str;
			while (*ptr != '\0')
				ptr++;
			return ptr - str;
		}
	public:
		static bool paraEval(const char expression[]) {
			int size = strLen(expression);
			Stack<char> stack(size);
			for (const char* c = expression; c < expression + size; c++) {
				switch (*c) {
				case '(':
				case ')':
				case '[':
				case ']':
				case '{':
				case '}':
					char topChar;
					if (!stack.Top(topChar)) {
						stack.Push(*c);
					} else {
						if (*c == topChar + 1 || *c == topChar + 2) {
							stack.Pop();
						}
					}
					break;
				default:
					break;
				}
			}
			return stack.IsEmpty();
		}
		static void infixToPostFix(const char infix[]) {
			auto precedence = [](char c) {
				switch (c) {
				case '+':
				case '-':
					return 1;
				case '*':
				case '/':
					return 2;
				default:
					return 0;
				}
			};
			int size = strLen(infix);
			Stack<char> stack(size);
			char postfix[size];
			char* j = postfix, top;

			for (const char* c = infix; c < infix + size; c++) {
				if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z') || (*c >= '0' && *c <= '9')) {
					*(j++) = *c;
				}
				else if (*c == '(') {
					stack.Push(*c);
				}
				else if (*c == ')') {
					while (stack.Top(top) && top != '(') {
						*(j++) = top;
						stack.Pop();
					}
					//paraEval func would make the if redundant but just in case
					if (stack.Top(top) && top == '(') {
						stack.Pop();
					}
				}
				else if (*c == '+' || *c == '-' || *c == '*' || *c == '/') {
					while (stack.Top(top) && top != '(' && precedence(top) >= precedence(*c)) {
						*(j++) = top;
						stack.Pop();
					}
					stack.Push(*c);
				}
			}
			while (!stack.IsEmpty()) {
				stack.Top(top);
				*(j++) = top;
				stack.Pop();
			}
			*j = '\0';
			std::cout << postfix << '\n';
		}
		static void evaluatePostfix(const char postfix[]) {
			int size = strLen(postfix);
			Stack<float> stack(size);
			float num1, num2, result;
			for (const char* c = postfix; c < postfix + size; c++) {
				if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z') || (*c >= '0' && *c <= '9')) {
					stack.Push(*c - '0');
				}
				else {
					num1 = stack.Top();
					stack.Pop();
					num2 = stack.Top();
					stack.Pop();
					switch (*c) {
					case '+':
						result = num1 + num2;
						break;
					case '-':
						result = num2 - num1;
						break;
					case '*':
						result = num1 * num2;
						break;
					case '/':
						result = num2 / num1;
						break;
					default:
						break;
					}
					stack.Push(result);
				}
			}
			std::cout << stack.Top() << '\n';
		}
};

int main() {
	char paranthesis_check[] = "( x + y ) * ( w / z )";
	std::cout << "Expression: " << paranthesis_check << '\n';
	std::cout << "Expression is valid: ";
	if (expressionEval::paraEval(paranthesis_check)) std::cout << "true"; else std::cout << "false"; std::cout << '\n';

	std::cout << "Infix expression: ";
	char infix1[] = "(9/(2-3+4))*(5-6)*7";
	std::cout << infix1 << '\n';
	std::cout << "Postfix expression: ";
	expressionEval::infixToPostFix(infix1);

	std::cout << "Infix expression, precedence checks required: ";
	char infix2[] = "1/2-3+4*5-1*3";
	std::cout << infix2 << '\n';
	std::cout << "Postfix expression: ";
	expressionEval::infixToPostFix(infix2);

	std::cout << "Postfix expression: ";
	char postfix[] = "923-4+/56-*7*";
	std::cout << "Postfix expression evaluation: ";
	expressionEval::evaluatePostfix(postfix);

	return 0;
}