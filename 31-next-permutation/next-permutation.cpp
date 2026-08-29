class Solution {
public:
    void reverse(vector<int>& nums , int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i + 1]) i--;
        int j= n - 1;
        if(i>=0){
            while(nums[i]>=nums[j]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums,i + 1,n-1);
        }
};