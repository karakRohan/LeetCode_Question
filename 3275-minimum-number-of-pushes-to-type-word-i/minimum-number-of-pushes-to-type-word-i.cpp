class Solution {
public:
    int minimumPushes(string word) 
    {
        int n = word.size(), ans = 0;
        while(n>0)
        {
            ans+=n; 
            n=n-8;
        }
        return ans;
    }
};