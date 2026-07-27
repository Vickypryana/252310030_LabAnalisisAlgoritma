#include <iostream>
using namespace std;

const int MAX = 5;
int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void Push(int nilai) {
    if (isFull()) return;
    top++;
    stack[top] = nilai;
}

void Pop() {
    if (isEmpty()) return;
    top--;
}

void Display() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {
    Push(621);
    Push(999);
    Push(201);
    Push(94);
    Push(124);
    Display();
    return 0;
}
