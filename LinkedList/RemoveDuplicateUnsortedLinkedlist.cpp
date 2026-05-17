#include<iostream>
#include<map>
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
    while(temp != NULL) {
        Node* curr = temp;
        Node* runner = temp -> next;
        while(runner != NULL) {
            if(runner -> data == temp -> data) {
                curr -> next = runner -> next;
                if(runner == tail) {
                    tail = curr;
                }
                Node* temp = runner;
                runner = runner -> next;
                delete temp;
            } else {
                curr = runner;
                runner = runner -> next;
            }
        }
        temp = temp -> next;
    }
    return head;
}
Node* OptimizedremoveDuplicate(Node* &head, Node* &tail) {
    if(head == NULL && tail == NULL) {
        return head;
    }
    map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL) {
        if(visited[curr -> data] == true) {
            prev -> next = curr -> next;
            if(curr == tail) {
                tail = prev;
            }
            Node* temp = curr;
            curr = curr -> next;
            delete temp;
        } else {
            visited[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    InsertHead(head, tail, 10);
    InsertTail(head, tail, 40);
    InsertTail(head, tail, 30);
    InsertTail(head, tail, 40);
    InsertTail(head, tail, 20);
    InsertTail(head, tail, 50);
    InsertTail(head, tail, 30);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    removeDuplicate(head, tail);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    InsertHead(head, tail, 55);
    InsertTail(head, tail, 10);
    InsertTail(head, tail, 55);
    InsertTail(head, tail, 40);
    InsertTail(head, tail, 20);
    InsertTail(head, tail, 40);
    InsertTail(head, tail, 10);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    OptimizedremoveDuplicate(head, tail);
    Print(head, tail);
    cout<<"Head is "<<head -> data<<endl;
    cout<<"Tail is "<<tail -> data<<endl;

    return 0;
}