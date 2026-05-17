// Reverse first K of a Queue
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n = q.size();
        stack<int> s;
        for(int i = 0; i < k; i++) {
            int element = q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }
        int t = n - k;
        while(t--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};