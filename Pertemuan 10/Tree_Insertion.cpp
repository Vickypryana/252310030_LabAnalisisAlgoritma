#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		
		Node (int value) {
			data = value;
			left = NULL;
			right = NULL;
		}
};

int main() {
	Node* root = new Node(14);
	root->left = new Node(6);
	root->right = new Node(2);
	root->left->left = new Node(2);
	root->left->right = new Node(13);
	root->left->right->left = new Node(7);
	root->right->left = new Node(19);
	root->right->right = new Node(33);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(41);
	
	cout << "Tree Insertion: " << root->right->left->left->data << " " << root->right->right->data << " " << root->right->left->right->data;
	
	return 0;
}
