#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void preorder(Node* root) {
	if(root == NULL) return;
	
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if(root == NULL) return;
	
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if(root == NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}


int main() {
	Node* root = createNode(7);
	root->left = createNode(14);
	root->right = createNode(83);
	root->left->left = createNode(91);
	root->left->right = createNode(102);
	root->right->left = createNode(192);
	root->right->right = createNode(932);
	root->left->right->left = createNode(31);
	root->left->right->right = createNode(87);
	root->right->right->left = createNode(153);
	root->left->right->left->left = createNode(93);
	root->right->right->left->left = createNode(772);
	root->right->right->left->right = createNode(812);
	root->left->right->left->left->left = createNode(24);
	root->left->right->left->left->right = createNode(78);
	
	cout << "== Tree Traversal ==" << endl;
	cout << "\nPREORDER: ";
	preorder(root);
	cout << endl;
	
	cout << "\nINORDER: ";
	inorder(root);
	cout << endl;
	
	cout << "\nPOSTORDER: ";
	postorder(root);
	cout << endl;
	
	return 0;
}
