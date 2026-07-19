class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0,maxSum=nums[0], currMax=0, minSum=nums[0],currMin=0;
        int n = nums.size();
        for (int i=0;i<n;i++) {
            totalSum+=nums[i];
            currMax=max(nums[i],currMax+nums[i]);
            maxSum=max(maxSum,currMax);
            currMin=min(nums[i],currMin+nums[i]);
            minSum=min(minSum,currMin);
        }
        if (maxSum<0)return maxSum;
        return max(maxSum,totalSum-minSum);
    }
};