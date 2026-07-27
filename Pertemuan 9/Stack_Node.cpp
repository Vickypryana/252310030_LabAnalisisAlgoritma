#include<iostream>
using namespace std;

struct Node {
	Node* next;
	int data;
};

class Stack {
	private:
		Node* top;
		int size;
		
	public:
		Stack() {
			top = NULL;
			size = 0;
		}
		
		void insert(int data) {
			Node* node = new Node();
			node->data = data;
			
			if (top == NULL) {
				top = node;
				top->next = NULL;
			} else {
				node->next = top;
				top = node;
			}
			size++;
		}
		
		void pop() {
			Node* temp = top;
			top = top->next;
			delete temp;
			size--;
		}
		
		void printStack() {
			Node* temp = top;
			while (temp != NULL) {
				cout << temp->data << ' ';
				temp = temp->next;
			}
			cout << endl;
		}
		
		int peek() {
			return top->data;
		}
		
		int getSize() {
			return size;
		}
};

int main() {
	Stack* stack = new Stack();
	
	stack->insert(99);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	stack->insert(31);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	cout << "Isi dari stack: " << endl;
	stack->printStack();
	
	stack->pop();
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	stack->insert(7);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	stack->insert(45);
	cout << "Elemen teratas dari stack: " << stack->peek() << endl;
	
	cout << "Isi dari stack: " << endl;
	stack->printStack();
	
	return 0;
}
