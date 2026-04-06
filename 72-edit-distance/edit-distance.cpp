// Method 2 :- Solution in Dp
class Solution {
public:

    int dp[505][505];
    int f(string &s1, string &s2, int i, int j){
        if(i == s1.size()) return s2.size() - j; // 4,1
        if(j == s2.size()) return s1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(s1,s2, i+1, j+1);
        return dp[i][j] = min({1+f(s1,s2,i+1,j+1),1 + f(s1,s2,i+1,j), 1 + f(s1,s2,i,j+1)});
    }
    int minDistance(string s1, string s2) {
        memset(dp, 0, sizeof dp);

        // base case
        for(int j = 0; j < s2.size(); j++){
            int i = s1.size();
            dp[i][j] = s2.size() - j;
        }
        for(int i = 0; i < s1.size(); i++){
            int j = s2.size();
            dp[i][j] = s1.size() - i;
        }
        // Bottom Up
        for(int i = s1.size() - 1; i >= 0; i--){
            for(int j = s2.size() - 1; j >= 0; j--){
                if(s1[i] == s2[j]) {
                    dp[i][j] = f(s1,s2, i+1, j+1);
                }
                else {
                    dp[i][j] = min({1 + dp[i+1][j+1], 1 + dp[i+1][j], 1 + dp[i][j+1]});
                }
            }
        }
        //return f(word1, word2, 0, 0 );
        return dp[0][0];
    }
};