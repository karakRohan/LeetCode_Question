class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sdigit=0,ddigit=0; // s = single , d = double
            for (int i=0;i< nums.size();i++){
            if (nums[i]>=10 )ddigit+=nums[i];
            else sdigit+=nums[i];
        }
        return sdigit!=ddigit;
    }
};