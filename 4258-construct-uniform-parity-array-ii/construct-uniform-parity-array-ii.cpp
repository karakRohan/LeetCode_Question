class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,n=nums1.size(), minOdd=INT_MAX, minEven=INT_MAX;
        for(int x:nums1){
            if(x % 2){
                odd++;
                minOdd=min(minOdd, x);
            }
            else minEven=min(minEven, x);
        }
        if(odd==0 || odd==n) return true;
        if(minEven- minOdd >= 1) return true;
        return false;
    }
};