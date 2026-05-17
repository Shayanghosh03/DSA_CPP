#include<iostream>
#include<queue>
using namespace std;

int main() {
    // Max Heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(45);
    maxHeap.push(12);
    maxHeap.push(67);
    maxHeap.push(26);
    
    cout<<"Element at top position: "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"Element at top position: "<<maxHeap.top()<<endl;

    cout<<"Size is"<<maxHeap.size()<<endl;

    if(maxHeap.empty()) {
        cout<<"Empty"<<endl;
    } else {
        cout<<"Not Empty"<<endl;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(25);
    minHeap.push(55);
    minHeap.push(65);
    minHeap.push(23);

    cout<<"Element at top position: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element at top position: "<<minHeap.top()<<endl;

    cout<<"Size is: "<<minHeap.size()<<endl;

    if(minHeap.empty()) {
        cout<<"Empty"<<endl;
    } else {
        cout<<"Not Empty"<<endl;
    }

    return 0;
}