// First negative in every window of size k
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        deque<int> d;
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) {
                d.push_back(i);
            }
        }
        if(d.size() > 0) {
            ans.push_back(arr[d.front()]);
        } else {
            ans.push_back(0);
        }
        for(int i = k; i < n; i++) {
            if(!d.empty() && i - d.front() >= k) {
                d.pop_front();
            }
            if(arr[i] < 0) {
                d.push_back(i);
            }
            if(d.size() > 0) {
                ans.push_back(arr[d.front()]);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};