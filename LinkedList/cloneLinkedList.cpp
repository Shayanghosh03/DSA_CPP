#include<iostream>
using namespace std;
#include<unordered_map>
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
        // Step 2 Clone a map
        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        //Step 3 arrange the random
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL) {
            cloneNode -> random = oldToNew[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};