#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max;
        int max_value = 0;
        for(int i = prices.size()-1; i>=0; i--) {
            if(max_value < prices[i]) {
                max_value = prices[i];
            }
            max.push_back(max_value);
        }
        reverse(max.begin(), max.end());
        int ans = 0;
        for(int i=0; i<prices.size(); i++) {
            if(max[i] - prices[i] > ans) {
                ans = max[i] - prices[i];
            }
        }
        return ans;
    }
};