// Brute Force
class Solution {
public:
    int mostWordsFound(vector<string>& s) { // s = sentences
        int i,k,m=0;
        for( i=0;i<s.size();i++){
            int count=0;
            string j=s[i];
            for(k=0;k<j.size();k++){
                if(j[k]==' ') count++;
            }
            m=max(count,m);
        }
        return m+1;
    }
};