class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();

        // Step 1: Build LCS table // LCS - Longest Common Subsequence
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        // Step 2: Build answer string
        string res = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                res += a[i - 1];  // same char, take once
                i--; j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                res += a[i - 1];  // move up
                i--;
            } 
            else {
                res += b[j - 1];  // move left
                j--;
            }
        }

        // Add leftover characters
        while (i > 0) {
            res += a[i - 1];
            i--;
        }
        while (j > 0) {
            res += b[j - 1];
            j--;
        }

        // reverse because we built backwards
        reverse(res.begin(), res.end());
        return res;
    }
};

// result -> str1 -> str2
//take all the characters of str1 and all the characters of str2
// LCS(str1, str2)