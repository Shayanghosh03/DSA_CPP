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
void insertNode(Node* &Head, int data) {
    Node* newNode = new Node(data);
    if(Head == NULL) {
        Head = newNode;
    } else {
        Node* temp = Head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void Print(Node* &Head) {
    Node* temp = Head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"X"<<endl;
}
int getLength(Node* &Head) {
    int len = 1;
    Node* temp = Head;
    while(temp -> next != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}
void middleNode(Node* &Head) {
    Node* temp = Head;
    int length = getLength(Head);
    int ans = (length / 2) + 1;
    int cnt = 1;
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    cout<<"Middle Node is "<<temp -> data<<endl;
}
int main() {
    Node* Head = NULL;

    insertNode(Head, 10);
    insertNode(Head, 20);
    insertNode(Head, 30);
    insertNode(Head, 40);
    insertNode(Head, 50);
    Print(Head);
    cout<<"length of the list is "<<getLength(Head)<<endl;

    middleNode(Head);

    return 0;
}