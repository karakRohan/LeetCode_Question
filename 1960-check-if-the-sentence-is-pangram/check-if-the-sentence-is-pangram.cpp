class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> v(26,0);
        for(int i =0;i<s.size();i++)v[s[i]-'a']++;
        for(int i =0;i<v.size();i++)
            if(v[i]== 0)return 0;
        return 1;
    }
};