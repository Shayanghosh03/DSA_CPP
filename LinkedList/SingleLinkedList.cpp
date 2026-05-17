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

    // Distructor
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            this -> next = NULL;
            delete next;
        }
        cout<<"Memory is free for the value - "<<value<<endl;
    }
};

void InsertHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void Print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<endl;
}

void InsertTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtPos(Node* &head, Node* &tail, int pos, int data) {
    Node *temp = head;
    int cnt = 1;

    if(pos == 1) {
        InsertHead(head, data);
        return;
    }
    if(temp -> next == NULL) {
        InsertTail(tail, data);
        return;
    }
    while(cnt < pos - 1) {
        temp = temp -> next;
        cnt++;
    }
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void DeleteNode(int pos, Node* &head, Node* &tail) {
    if(pos == 1) {
        Node* temp = head;
        head = temp -> next;
        delete temp;
    } else {
        int cnt = 1;
        Node* curr = head;
        Node* prev = NULL;
        while(cnt < pos) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr -> next == NULL) {
            tail = prev;
        }
        prev -> next = curr -> next;
        delete curr;
    }
}
int main() {
    Node* node1 = new Node(10);
    cout<<node1 -> data<<endl;

    Node* head = node1;
    Node* tail = node1;
    // InsertHead(head, 11);
    // InsertHead(head, 12);
    // InsertHead(head, 15);
    // InsertHead(head, 30);

    InsertTail(tail, 11);
    InsertTail(tail, 12);
    InsertTail(tail, 13);
    InsertTail(tail, 14);

    cout<<"Head is- "<<head -> data<<endl;
    cout<<"Tail is- "<<tail -> data<<endl;
    Print(head);

    InsertAtPos(head, tail, 3, 55);
    Print(head);

    DeleteNode(1, head, tail);
    Print(head);
    cout<<"Head is- "<<head -> data<<endl;
    cout<<"Tail is- "<<tail -> data<<endl;
    return 0;
}