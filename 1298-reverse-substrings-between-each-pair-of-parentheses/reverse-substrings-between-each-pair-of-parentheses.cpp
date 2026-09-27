class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> v;
        string current;
        for(int i =0 ; i <s.size() ; i++){
            if(s[i]== '('){
                v.push(current);
                current= "";
            }
            else if(s[i]== ')'){
                reverse(current.begin(),current.end());
                current =v.top()+current;
                v.pop();
            }
            else current+=s[i];
        }
        return current;
    }
};