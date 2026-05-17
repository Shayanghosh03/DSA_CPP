#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL; 
    }

    ~Node() {
        int value = this -> data;
        cout<<value<<" is deleted"<<endl;
    }
};

void insertNodeLast(Node* &Head, int data) {
    if(Head == NULL) {
        Node* newNode = new Node(data);
        Head = newNode;
        newNode -> next = newNode;
        newNode ->prev = newNode;
        return;
    } else {
        Node* newNode = new Node(data);
        Head -> prev -> next = newNode;
        newNode -> prev = Head -> prev;
        newNode -> next = Head;
        Head -> prev = newNode;
    }
}
void  insertNodeFirst(Node* &Head, int data) {
    if(Head == NULL) {
        Node* newNode = new Node(data);
        Head = newNode;
        newNode -> next = newNode;
        newNode ->prev = newNode;
        return;
    } else {
        Node* newNode = new Node(data);
        newNode -> prev = Head -> prev;
        Head -> prev -> next = newNode;
        newNode -> next = Head;
        Head -> prev = newNode;
        Head = newNode;
    }
}
void deleteNode(Node* &Head, int pos) {
    if(Head == NULL) {
        cout<<"Linked List is Empty"<<endl;
    } else {
        Node* temp = Head;
        if(pos == 1) {
            if(temp->next == temp) {
                delete temp;
                Head = NULL;
                return;
            }
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp ->prev;
            Head = temp -> next;
            temp -> next = NULL;
            temp -> prev = NULL;
            delete temp;
            return;
        }
       
        int cnt = 1;
        while(cnt < pos) {
            temp = temp -> next;
            cnt++;
            if(temp == Head) {
                cout<<"Position out  of range"<<endl;
                return;
            }
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
}
void printNode(Node* &Head) {
    if(Head == NULL) {
        cout<<"LinkedList is empty"<<endl;
    } else {
        Node* temp = Head;
        do {
            cout<<temp -> data<<" ->";
            temp = temp -> next;
        } while(temp != Head);
        cout<<"X"<<endl;
    }
}
int main() {
    Node* Head = NULL;
    insertNodeLast(Head, 10);
    insertNodeLast(Head, 20);
    insertNodeLast(Head, 30);
    printNode(Head);

    insertNodeFirst(Head,55);
    insertNodeFirst(Head,58);
    printNode(Head);

    deleteNode(Head, 3);
    printNode(Head);
    deleteNode(Head, 1);
    printNode(Head);
    return 0;
}