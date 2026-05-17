#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        // MinHeap create
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : arr) {
            pq.push(i);
        }
        int cost = 0;
        
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};