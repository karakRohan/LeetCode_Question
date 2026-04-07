class Solution {
public:
    
    // function for normal house robber (linear)
    int solve(vector<int>& nums, int start, int end) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]
        
        for (int i = start; i <= end; i++) {
            int take = nums[i] + prev2;
            int notTake = prev1;
            
            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if (n == 1) return nums[0];
        // case 1: skip last house
        int case1 = solve(nums, 0, n - 2);
        // case 2: skip first house
        int case2 = solve(nums, 1, n - 1);
        return max(case1, case2);
    }
};