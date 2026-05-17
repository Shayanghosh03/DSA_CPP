#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        // Using Max Heap SOlve this 
        int n = arr.size() - 1;
        // Step -> 1
        priority_queue<int> pq;
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        // Step -> 2
        for(int i = k; i <= n; i++) {
            if(pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // Step -> 3
        int ans = pq.top();
        return ans;
    }
};