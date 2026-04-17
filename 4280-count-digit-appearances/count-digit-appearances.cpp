class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        char d = '0' + digit;
        for(int num :nums){
            string s=to_string(num);
            for(char c:s){
                if(c==d) count++;
            }
        }
        return count;
    }
};