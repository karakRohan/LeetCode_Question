class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size(),maxi =0,sum= 0;
        for(int i=0; i<n;i++)
        {
            maxi= max(maxi, nums[i]);
            sum+= nums[i];
        }
        return maxi*n - sum;
    }
};