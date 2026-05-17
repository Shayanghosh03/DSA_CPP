#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;   // Min Heap
    }
};

Node* mergeKLists(vector<Node*> &listArray) {
    
    // Min Heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = listArray.size();

    if (k == 0) {
        return NULL;
    }

    // Push first node of each linked list
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (!minHeap.empty()) {
        Node* top = minHeap.top();
        minHeap.pop();

        // Push next node of popped node
        if (top->next != NULL) {
            minHeap.push(top->next);
        }

        // Build merged linked list
        if (head == NULL) {
            head = tail = top;
        } 
        else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}