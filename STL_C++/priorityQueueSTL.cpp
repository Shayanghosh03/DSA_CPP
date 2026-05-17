#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pmax; //maxHeap;
    priority_queue<int, vector<int>, greater<int>> pmin; //minHeap

    pmax.push(10);
    pmax.push(99);
    pmax.push(50);
    pmax.push(77);
    pmax.push(89);
    pmax.push(90);

    int m = pmax.size();
    for(int i = 0; i < m; i++) {
        cout<<pmax.top()<<" ";
        pmax.pop();
    }
    cout<<endl;

    pmin.push(10);
    pmin.push(45);
    pmin.push(77);
    pmin.push(95);
    pmin.push(55);
    pmin.push(88);

    int n = pmin.size();
    for(int i = 0; i < n; i++) {
        cout<<pmin.top()<<" ";
        pmin.pop();
    }
    cout<<endl;

    return 0;
}