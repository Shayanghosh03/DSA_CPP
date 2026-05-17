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
bool detectLoop(Node* head) { // TC->O(n) & SC->O(n)
    if(head == NULL) {
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}
// Optimize solution using Floyd's Cycle Detection algo
Node* FloydCycleDetection(Node* &head) {
    if(head == NULL)
        return 0;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            return fast;
        }
    }
    return 0;
}
Node* StartingNodeinTheLoop(Node* head) {
    if(head == NULL)
        return 0;
    Node* fast = FloydCycleDetection(head);
    if(fast == NULL) {
        return NULL;
    }
    Node* slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
void removeLoop(Node *head) {
    if(head == NULL) {
        return;
    }
    Node* start = StartingNodeinTheLoop(head);
    Node* temp = start;
    while(temp -> next != start) {
        temp = temp -> next;
    }
    temp -> next = NULL;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    InsertHead(head, tail, 10);
    InsertTail(head, tail, 20);
    InsertHead(head, tail, 30);
    InsertHead(head, tail, 55);
    InsertTail(head, tail, 67);
    InsertHead(head, tail, 89);
    Print(head, tail);

    // LOOP CREATED
    tail -> next = head -> next;
    
    cout<<"Head is- "<<head -> data<<endl;
    cout<<"Tail is- "<<tail -> data<<endl;

    if(detectLoop(head)) {
        cout<<"Loop is present"<<endl;
    } else {
        cout<<"Loop is not present"<<endl;
    }

    if(FloydCycleDetection(head)) {
        cout<<"Loop is present"<<endl;
    } else {
        cout<<"Loop is not present"<<endl;
    }

    Node* start = StartingNodeinTheLoop(head);
    if(start != NULL) {
        cout<<"Starting Node in the loop is "<<start -> data<<endl;
    } else {
        cout<<"No Loop is exsists"<<endl;
    }

    removeLoop(head);
    Print(head, tail);

    return 0;
}