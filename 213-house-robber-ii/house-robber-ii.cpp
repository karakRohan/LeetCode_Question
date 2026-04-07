// Method - 2
class Solution {
public:
    
    // normal house robber (linear DP)
    int solve(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<int> dp(n, 0);
        
        dp[0] = nums[start];
        
        for (int i = 1; i < n; i++) {
            int take = nums[start + i];
            if (i > 1) take += dp[i - 2];            
            int notTake = dp[i - 1];            
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if (n == 1) return nums[0];
        // case 1: skip last
        int case1 = solve(nums, 0, n - 2);
        // case 2: skip first
        int case2 = solve(nums, 1, n - 1);
        return max(case1, case2);
    }
};