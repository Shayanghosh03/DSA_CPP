// Sort 0's 1's and 2's in LinkedList
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
    ~Node() {}
};
void insertNode(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}
void printNode(Node* &head) {
    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"X"<<endl;
}
Node* sortList(Node* &head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == 0) {
            zeroCount++;
        } else if(temp -> data == 1) {
            oneCount++;
        } else if(temp -> data == 2) {
            twoCount++;
        }
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp -> data = 0;
            zeroCount--;
        } else if(oneCount != 0) {
            temp -> data = 1;
            oneCount--;
        } else if(twoCount != 0) {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
    return head;
}
// With out data replacement
void insertAtTail(Node* &tail, Node* curr) {
    tail -> next = curr;
    tail = curr;
}
Node* sortListOP(Node* head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr != NULL) {
        int value = curr -> data;
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        } else if(value == 1) {
            insertAtTail(oneTail, curr);
        } else if(value == 2) {
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }
    // Merge this 3 lists
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    } else {
        zeroTail -> next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}
int main() {
    Node* head = NULL;
    insertNode(head, 0);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 0);
    printNode(head);

    cout<<"After Sort this List"<<endl;
    sortList(head);
    printNode(head);

    cout<<"With out replace data"<<endl;
    sortListOP(head);
    printNode(head);

    return 0;
}