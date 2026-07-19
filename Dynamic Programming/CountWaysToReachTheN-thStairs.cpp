//Count Ways To Reach The N-th Stairs
#include <iostream>
#include<vector>
#define MOD 1000000007
using namespace std;
// Recursion
int solve(long long nStairs, int i) {
    // Base case 
    if(i == nStairs) {
        return 1;
    }
    if(i > nStairs) {
        return 0;
    }
    return (solve(nStairs, i+1) + solve(nStairs, i+2)) % MOD;
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    int ans = solve(nStairs, 0);
    return ans;
}

// Memoization (Top-Down DP)
int solve2(int n, vector<int> &dp) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (solve2(n - 1, dp) + solve2(n - 2, dp)) % MOD;
    return dp[n];
}

int countDistinctWays2(int nStairs) {
    vector<int> dp(nStairs + 1, -1);
    return solve2(nStairs, dp);
}

// Tabulation (Bottom-Up DP)
int countDistinctWays3(int nStairs) {
    vector<long long> dp(nStairs + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= nStairs; i++) {
        dp[i] = dp[i - 1];
        if (i >= 2)
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    return dp[nStairs];
}

// Space Optimized (Best Solution)
int countDistinctWays4(int nStairs) {
    if (nStairs == 0)
        return 1;

    long long prev2 = 1; // dp[0]
    long long prev1 = 1; // dp[1]

    for (int i = 2; i <= nStairs; i++) {
        long long curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}