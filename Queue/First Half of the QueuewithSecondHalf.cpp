// Interleave the First Half of the Queue with Second Half
#include<iostream>
#include<queue>
using namespace std;
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> newq;
        int n = q.size();
        int length = n / 2;
        while(length > 0) {
            int val = q.front();
            q.pop();
            newq.push(val);
            length--;
        }
        while(!newq.empty()) {
            int val = newq.front();
            newq.pop();
            q.push(val);
            val = q.front();
            q.pop();
            q.push(val);
        }
    }
};