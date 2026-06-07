// Top Down -> Recursion + Memoizaton
#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    // Base Case
    if(n <= 1) {
        return n;
    }
    // Step -> 3
    if(dp[n] != -1) {
        return dp[n];
    }

    // Step -> 2
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    // Step -> 1
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp) << endl;

    return 0;
}