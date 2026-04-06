// Solution In String
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size(); // length of first string
        int m = word2.size(); // length of second string

        // dp table where dp[i][j] = min operations to convert
        // first i chars of word1 to first j chars of word2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // base case: convert to empty string
        for (int i = 0; i <= n; i++) dp[i][0] = i; // delete all
        for (int j = 0; j <= m; j++) dp[0][j] = j; // insert all

        // fill dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // if characters match → no operation
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else {
                    // 3 operations
                    int insertOp = dp[i][j - 1];
                    int deleteOp = dp[i - 1][j];
                    int replaceOp = dp[i - 1][j - 1];

                    // take minimum + 1 operation
                    dp[i][j] = 1 + min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }

        return dp[n][m]; // final answer
    }
};