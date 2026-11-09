class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={};
        // count
        for(char c: magazine){
            freq[c-'a']++;
        }
        // then consume
        for(char ch : ransomNote){
            if(freq[ch-'a']==0)return false;
            freq[ch-'a']--;
        }
        return true;
    }
};