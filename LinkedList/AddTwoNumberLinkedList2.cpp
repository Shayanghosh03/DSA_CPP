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
Node<int>* reverse(Node<int>* &temp) {
    Node<int>* curr = temp;
    Node<int>* next = NULL;
    Node<int>* prev = NULL;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertTail(Node<int>* &head, Node<int>* &tail, int digit) {
    Node<int>* newNode = new Node<int>(digit);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}
Node<int>* add(Node<int>* &first, Node<int>* &second) {
    int carry = 0;
    Node<int>* ansHead = NULL;
    Node<int>* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;
        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
    }
    return ansHead;
}
Node<int>* addTwoList(Node<int>* &first, Node<int>* second) {
    // Step1 Reverse the Linkedlist
    first = reverse(first);
    second = reverse(second);

    // Step2 Add linkedList
    Node<int>* ans = add(first, second);

    //step3 reverse ans
    ans = reverse(ans);

    return ans;
}
int main() {
    Node<int>* first = NULL;
    insertNode(first, 1);
    insertNode(first, 2);
    insertNode(first, 3);

    Node<int>* second = NULL;
    insertNode(second, 5);
    insertNode(second, 4);
    insertNode(second, 6);
    insertNode(second, 1);

    cout<<"First List is"<<endl;
    printNode(first);
    cout<<"Second List is"<<endl;
    printNode(second);

    cout<<"Add two List"<<endl;
    Node<int>* result = addTwoList(first, second);
    printNode(result);

    return 0;
}