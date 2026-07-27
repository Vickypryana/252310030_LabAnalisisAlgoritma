#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
	private:
		Node* front;
		Node* rear;
		
	public:
		Queue() {
			front = NULL;
			rear = NULL;
		}
		
		void enqueue(int data) {
			Node* new_node = new Node();
			new_node->data = data;
			new_node->next = NULL;
			
			if (rear == NULL) {
				front = new_node;
				rear = new_node;
				return;
			}
			
			rear->next = new_node;
			rear = new_node;
		}
		
		void dequeue() {
			if (front == NULL) {
				cout << "Antrian kosong (Queue is empty)." << endl;
				return;
			}
			
			Node* temp = front;
			
			front = front->next;
			
			if (front == NULL) 
			rear = NULL;
			
			delete temp;
		}
		
		int front_element() {
			if (front == NULL) {
				cout << "Antrian kosong." << endl;
				return -1;
			}
			return front->data;
		}
		
		bool isEmpty() {
			return (front == NULL);
		}
};

int main() {
	Queue q;
	
	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(9);
	
	cout << "Elemen terdepan adalah: " << q.front_element() << endl;
	
	q.dequeue();
	
	cout << "Elemen terdepan sekarang: " << q.front_element() << endl;
	
	q.dequeue();
	
	return 0;
}
