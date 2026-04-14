class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m =mat.size();
        int n =mat[0].size();
        
        queue<pair<int,int>> q;

        // Step 1: Push all 0's into queue and mark 1's as -1
        for(int i = 0; i <m; i++){
            for(int j =0; j <n; j++){
                if(mat[i][j] ==0){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1; // mark unvisited
                }
            }
        }
        // Directions: up, down, left, right
        vector<pair<int,int>> dir ={{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Step 2: BFS
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto d : dir){
                int nr =r + d.first;
                int nc =c + d.second;

                // check boundary and unvisited
                if(nr>= 0 && nc >= 0 && nr<m && nc < n && mat[nr][nc] == -1){
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};