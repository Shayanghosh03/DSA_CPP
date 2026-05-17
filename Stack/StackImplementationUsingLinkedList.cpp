#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << data << " is POP\n";
    }
};

void push(Node* &top, int data) {
    Node* newNode = new Node(data);
    newNode->next = top;   // Link new node to previous top
    top = newNode;         // Move top to new node
}

void printStack(Node* top) {
    if(top == NULL) {
        cout << "Empty Stack";
        return;
    }

    while(top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node* top = NULL;

    push(top, 10);
    push(top, 20);
    push(top, 30);
    push(top, 40);

    printStack(top);

    return 0;
}