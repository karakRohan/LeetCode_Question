class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                low++;
                high++;
            }
            else if (s[i] == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;      // treat as ')'
                high++;     // treat as '('
            }

            if (high < 0) return false; // too many ')'

            if (low < 0) low = 0; // we can't go below 0
        }

        return low == 0;
    }
};