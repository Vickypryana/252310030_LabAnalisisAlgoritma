#include<iostream>
using namespace std;

const int MAX = 5;

class Stack {
	private:
		int top;
		int stack[MAX];
		int items;
	
	public:
		Stack() {
			items = 0;
			top = -1;
		}
		
		int pop() {
			if (!items) {
				cout << "No items inserted yet." << endl;
				return -1;
			}
			int value = stack[top];
			top--;
			items--;
			return value;
		}
		
		void insert(int data) {
			top++;
			stack[top] = data;
			items++;
		}
		
		void printStack() {
			for (int i=0; i<=top; i++) {
				cout << stack[i] << ' ';
			}
			cout << endl;
		}
		
		int peek() {
			return stack[top];
		}
		
		int totalItems() {
			return items;
		}
};

int main() {
	Stack* stack = new Stack();
	stack->insert(13);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	stack->insert(200);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	cout << "Isi dari stack: " << endl;
	stack->printStack();
	
	stack->pop();
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	return 0;
}
