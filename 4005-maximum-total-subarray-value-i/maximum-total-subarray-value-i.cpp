class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < mn)mn = nums[i];
            if (nums[i] > mx)mx = nums[i];
        }
        return 1LL * k * (mx - mn);
    }
};