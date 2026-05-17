// With TC -> O(n) and SC -> O(n)
#include<iostream>
#include<vector>
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
bool checkPlaindrome(vector<int> &arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s <= e) {
        if(arr[s] != arr[e]) {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
bool isPlaindrome(Node<int>* &head) {
    if(head == NULL || head -> next == NULL) {
        return 1;
    }
    vector<int> arr;
    Node<int>* temp = head;
    while(temp != NULL) {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPlaindrome(arr);
}
int main() {
    Node<int>* head = NULL;
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
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