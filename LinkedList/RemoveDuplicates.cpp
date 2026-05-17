#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        cout<<value<<" is deleted"<<endl;
    }
};

void InsertHead(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head = temp;
}

void Print(Node* &head, Node* &tail) {
    if(tail == NULL && head == NULL) {
        cout<<"Empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"X"<<endl;
}

void InsertTail(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    if(tail == NULL && head == NULL) {
        tail = temp;
        head = temp;
        return;
    }
    tail -> next = temp;
    tail = tail -> next;
}
Node* removeDuplicate(Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp != NULL && temp -> next != NULL) {
        if(temp -> data == temp -> next -> data) {
            Node* duplicate = temp -> next;
            temp -> next = duplicate -> next;
            if(duplicate == tail) {
                tail = temp;
            }
            delete duplicate;
        } else {
            temp = temp -> next;
        }
    }
    return head;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    InsertHead(head, tail, 10);
    InsertTail(head, tail, 20);
    InsertTail(head, tail, 30);
    InsertTail(head, tail, 30);
    InsertTail(head, tail, 40);
    InsertTail(head, tail, 40);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    removeDuplicate(head, tail);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    return 0;
}