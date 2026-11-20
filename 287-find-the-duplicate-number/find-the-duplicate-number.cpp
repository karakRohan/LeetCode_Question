class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>arr;
        for(int i=0;i<n;i++){
            if(arr.count(nums[i]))return nums[i];
            else arr.insert(nums[i]);
        }
        return -1;
    }
};