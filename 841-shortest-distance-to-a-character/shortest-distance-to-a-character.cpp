class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, n);
        // Left to Right
        int prev = -n;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            ans[i] = i - prev;
        }
        // Right to Left
        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};