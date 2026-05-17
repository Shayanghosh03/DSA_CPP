#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<value<<" is deleted"<<endl;
    }
};

void insertNode(Node* &Tail, int element, int data) {
    if(Tail == NULL) {
        Node* newNode = new Node(data);
        Tail = newNode;
        newNode -> next = newNode;
    } else {
        Node* temp = Tail;
        while(temp -> data != element) {
            temp = temp -> next;
        }
        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void printNode(Node* &Tail) {
    if(Tail == NULL) {
        cout<<"Node is Empty"<<endl;
    } else {
        Node* temp = Tail;
        do {
            cout<<temp -> data<<" ->";
            temp = temp -> next;
        } while(temp != Tail);

        cout<<"X"<<endl;
    }
}

void deleteNode(Node* &Tail, int value) {
    if(Tail == NULL) {
        cout<<"LinkedList is Empty"<<endl;
    } else {
        Node* prev = Tail;
        Node* curr = prev -> next;
        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        if(curr == prev) {
            Tail = NULL;
        }
        if(Tail == curr) {
            Tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
int main() {
    Node* Tail = NULL;
    insertNode(Tail, 5, 10);
    printNode(Tail);

    // insertNode(Tail, 10, 11);
    // insertNode(Tail, 11, 16);
    // insertNode(Tail, 16, 20);
    // insertNode(Tail, 16, 25);
    // printNode(Tail);

    deleteNode(Tail, 10);
    printNode(Tail);
    return 0;
}