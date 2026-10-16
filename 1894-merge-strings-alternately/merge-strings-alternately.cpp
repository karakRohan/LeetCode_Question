class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int n1=word1.size(), n2=word2.size();
        int i=0, j=0;
        // Merge alternately
        while(i<n1 && j<n2) {
            result+=word1[i++];
            result+=word2[j++];
        }
        // Append remaining part of the longer string
        if (i<n1)result += word1.substr(i);
        if (j<n2)result += word2.substr(j);
        return result;
    }
};
