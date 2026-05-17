#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col) {
        this -> data = data;
        i = row;
        j = col;
    }
};
class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a -> data > b -> data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Step 1 -> Insert all the array's first element in the minHeap
    for(int i = 0; i < k; i++) {
        Node* temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2 ->  
    while(!minHeap.empty()) {
        Node* temp = minHeap.top();
        ans.push_back(temp -> data);
        minHeap.pop();

        int i = temp -> i;
        int j = temp -> j;

        if(j + 1 < arr[i].size()) {
            Node* next = new Node(arr[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;

}
