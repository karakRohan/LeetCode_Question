class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        // transpose 
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(m[i][j], m[j][i]);
        // reverse each row (manual swap)
        for(int i=0;i<n;i++){
            // int c=0, r=n-1;
            // while(c<r){
            //     swap(m[i][c], m[i][r]);
            //     c++; r--;
            // }
            reverse(m[i].begin(), m[i].end());
        }
    }
};