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
    cout<<"X"<<endl;
}

void InsertTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}
// Reverse LinkedList
Node* reverseList(Node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    } else {
        Node* prev = NULL;
        Node* forward = NULL;
        Node* curr = head;
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}
// Reverse LinkedList using recursion

void reverseListRecursion (Node* &head, Node* curr, Node* prev) {
    // Base Case
    if(curr == NULL) {
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    reverseListRecursion(head, forward, curr);
    curr -> next = prev;
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

    head = reverseList(head);
    Print(head);


    Node* curr = head;
    Node* prev = NULL;
    reverseListRecursion(head, curr, prev);
    Print(head);

    return 0;
}