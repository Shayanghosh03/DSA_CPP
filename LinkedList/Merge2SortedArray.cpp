#include<iostream>
using namespace std;
template <typename T>

class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};
void insertNode(Node<int>* &head, int data) {
    Node<int>* newNode = new Node<int>(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node<int>* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}
void printNode(Node<int>* &head) {
    if(head == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }
    Node<int>* temp = head;
    while(temp != NULL) {
        cout<<temp -> data<<"->";
        temp = temp -> next;
    }
    cout<<"X"<<endl;
}
Node<int>* solve(Node<int>* &first, Node<int>* &second) {
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    while(next1 != NULL && curr2 != NULL) {
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int>* sortTwoList(Node<int>* &first, Node<int>* &second) {
    if(first == NULL) {
        return second;
    }
    if(second == NULL) {
        return first;
    }
    if(first -> data <= second -> data) {
        solve(first, second);
    } else {
        solve(second, first);
    }
}
int main() {
    Node<int>* first = NULL;
    insertNode(first, 10);
    insertNode(first, 15);
    insertNode(first, 44);
    insertNode(first, 56);

    Node<int>* second = NULL;
    insertNode(second, 25);
    insertNode(second, 35);
    insertNode(second, 67);
    insertNode(second, 77);

    cout<<"First List is"<<endl;
    printNode(first);
    cout<<"Second List is"<<endl;
    printNode(second);

    cout<<"Merge Two Sorted Array"<<endl;
    sortTwoList(first, second);
    printNode(first); 

    return 0;
}