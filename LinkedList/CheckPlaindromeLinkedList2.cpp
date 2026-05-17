// With TC -> O(n) and SC -> O(1)
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
Node<int>* getMid(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
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
bool isPlaindrome(Node<int>* &head) {
    if(head == NULL || head -> next == NULL) {
        return 1;
    }
    // step1 Find Middle
    Node<int>* middle = getMid(head);
    // step2 reverse list after middle
    Node<int>* temp = middle -> next;
    middle -> next = reverse(temp);
    // step3 compare both halves
    Node<int>* head1 = head;
    Node<int>* head2 = middle -> next;
    while(head2 != NULL) {
        if(head1 -> data != head2 -> data) {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    // step4 repeat step2
    temp = middle -> next;
    middle -> next = reverse(temp);
    return true;
}
int main() {
    Node<int>* head = NULL;
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 10);
    printNode(head);

    cout<<"Cheking Plaindrome or not"<<endl;
    if(isPlaindrome(head)) {
        cout<<"Palindrome Number"<<endl;
    } else {
        cout<<"Not a Plindrome Number"<<endl;
    }

    return 0;
}