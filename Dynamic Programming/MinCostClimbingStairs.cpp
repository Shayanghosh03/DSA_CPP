// Min Cost Climbing Stairs
#include<iostream>
#include<vector>
using namespace std;

// Recursion
class Solution {
public:
    int solve(vector<int> &cost, int n) {
        // Base Case
        if(n==0) {
            return cost[0];
        }
        if(n==1) {
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

// Memoization (Top-Down DP)
class Solution1 {
public:
    int solve(vector<int> &cost, int n, vector<int> &dp) {
        // Base Case
        if(n==0) {
            return cost[0];
        }
        if(n==1) {
            return cost[1];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};
// Tabulation (Bottom-up DP)
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};

// Space Optimization
class Solution3 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};