class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        unordered_map<string,int>freq;

        while(ss1>>word)freq[word]++;
        while(ss2>>word)freq[word]++;
        vector<string>ans;
        for(auto it: freq){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};