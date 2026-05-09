class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Two Pass Solution
        int n = nums.size(), noz = 0, noo =0, notw=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) noz++;
            else if(nums[i]==1) noo++;
            else notw++; // notw = numbers of tows
        }
        // fill
        for(int i=0;i<n;i++){
            if(i<noz)nums[i] =0;
            else if(i<(noz+noo)) nums[i] = 1;
            else nums[i] = 2;
        }
        return;
    }
};