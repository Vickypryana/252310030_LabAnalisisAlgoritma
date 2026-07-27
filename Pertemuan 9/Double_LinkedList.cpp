#include <iostream>
using namespace std;

struct Node {
	Node* next;
	Node* previous;
	int data;
};

class LinkedList {
	private:
		Node* head;
		Node* tail;
		int length;
	
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			length = 0;
		}
		
		// dorong nilai baru ke ekor
		void push(int data) {
			Node* node = new Node();
			node->data = data;
			node->next = NULL;
			
			if (head == NULL) {
				node->previous = NULL;
				head = node;
				tail = node;
			} else {
				Node* temp = tail;
				tail->next = node;
				tail = node;
				node->previous = temp;
			}
			length++;
		}
		
		void insert(int data, int position) {
			if (position < 0 && position > length) {
				cout << "Tidak dapat insert diluar batas linked list." << endl;
				return;
			} 
			
			Node* node = new Node();
			node->data = data;
			
			if (position == 0) {
				// insert pada head
				node->previous = NULL;
				node->next = head;
				head = node;
			} else if (position == length) {
				// insert pada tail
				node->next = NULL;
				node->previous = tail;
				tail = node;
			} else {
				// kasus jika insert bukan pada bagian head atau tail
				Node* target = head;
				for (int i = 0; i < position - 1; i++) {
					// position di minus 1 agar elemen yang di insert berada pas pada index position
					target = target->next;
				}
				Node* temp = target->next;
				
				// sambung bagian depan
				target->next = node;
				node->next = temp;
				
				// sambung bagian belakang
				node->previous = target;
				temp->previous = node;
			}
			
			length++;
		}
		
		// versi AI yg dioptimisasi
//		void remove(int position) {
//		    Node* target = head;
//		
//		    for (int i = 0; i < position; i++) {
//		        target = target->next;
//		    }
//		
//		    if (target->previous) {
//		        target->previous->next = target->next;
//		    } else {
//		        head = target->next;  // removing head
//		    }
//		
//		    if (target->next) {
//		        target->next->previous = target->previous;
//		    } else {
//		        tail = target->previous;  // removing tail
//		    }
//		
//		    delete target;
//		    length--;
//		}
		
		// versi lebih manusiawi
		void remove(int position) {
			Node* targetNode = head;
			for (int i = 0; i < position; i++) {
				targetNode = targetNode->next;
			}
			
			if (targetNode == head && length == 1) {
				head = NULL;
				tail = NULL;
			} else if (targetNode == head) {
				head = head->next;
				head->previous = NULL;
			} else if (targetNode == tail) {
				tail = tail->previous;
				tail->next = NULL;
			} else {
				Node* prevNode = targetNode->previous;
				Node* nextNode = targetNode->next;
				prevNode->next = nextNode;
				nextNode->previous = prevNode;
			}
			
			delete targetNode;
			length--;
		}
		
		void printNodesFrontwards() {
			Node* node = head;
			while (node != NULL) {
				cout << node->data << ' ';
				node = node->next;
			}
			cout << endl;
		}
		
		void printNodesBackwards() {
			Node* node = tail;
			while (node != NULL) {
				cout << node->data << ' ';
				node = node->previous;
			}
			cout << endl;
		}
};

int main() {
	LinkedList* LL = new LinkedList();
	LL->push(4);
	LL->push(12);
	LL->push(14);
	LL->push(17);
	LL->push(19);
	LL->insert(200, 2);
	
	LL->printNodesBackwards();
	
	return 0;
}
