class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for (string a:words) {
            int j =a.size() - 1,i = 0;
            while (i<= j) {
                if (a[i]!=a[j])break;
                i++;
                j--;
            }
            if (i>j){
                ans= a;
                break;
            }
        }
        return ans;
    }
};