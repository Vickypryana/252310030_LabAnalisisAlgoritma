#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* HEAD = NULL;
Node* TAIL = NULL;

void Insert(int data) {
    Node* baru = new Node();
    baru->data = data;
    baru->prev = NULL;
    baru->next = NULL;
    
    if (HEAD == NULL) {
        HEAD = TAIL = baru;
    } else {
        TAIL->next = baru;
        baru->prev = TAIL;
        TAIL = baru;
    }
}

void DisplayForward() {
    Node* temp = HEAD;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void DisplayBackward() {
    Node* temp = TAIL;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) cout << " <-> ";
        temp = temp->prev;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Insert(24);
    Insert(10);
    Insert(33);
    Insert(33);
    
    cout << "HEAD: " << HEAD->data << endl;
    cout << "TAIL: " << TAIL->data << endl;
    DisplayForward();
    return 0;
}
