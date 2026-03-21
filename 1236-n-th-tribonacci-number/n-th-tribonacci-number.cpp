// Method :- Recursion + Memoization

class Solution {
public:
    vector<int> dp;

    int trib(int n) {
        // base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // if already calculated
        if (dp[n] != -1) return dp[n];

        // compute and store
        dp[n] = trib(n - 1) + trib(n - 2) + trib(n - 3);
        return dp[n];
    }

    int tribonacci(int n) {
        dp = vector<int>(n + 1, -1); // initialize dp
        return trib(n);
    }
};

