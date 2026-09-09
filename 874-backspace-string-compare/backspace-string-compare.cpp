class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>st,gt;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') st.push(s[i]);
            else if(!st.empty())st.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#') gt.push(t[i]);
            else if(!gt.empty()) gt.pop();
        }
        if(st==gt) return true;
        return false;
    }
};