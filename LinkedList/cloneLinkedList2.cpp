#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
private:
    void insertTail(Node* &head, Node* &tail, int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // Step 1 Create a clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL) {
            insertTail(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }
        //step 2 Clone Node add between original List
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        // step 3 copy the random pointer
        temp = head;
        while(temp != NULL) {
            if(temp -> next != NULL) {
                if(temp -> random != NULL) {
                    temp -> next -> random = temp -> random -> next;
                } else {
                    temp -> next -> random = NULL;
                }
            }
            temp = temp -> next -> next;
        }
        // Step 4 revert changing on the step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if(originalNode != NULL) {
                cloneNode -> next = originalNode -> next;
            } else {
                cloneNode -> next = NULL;
            }
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};