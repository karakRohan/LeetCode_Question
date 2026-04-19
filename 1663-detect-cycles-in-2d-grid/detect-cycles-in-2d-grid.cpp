class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid) {
        vis[r][c] = 1;
        // 4 directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i= 0; i < 4; i++) {
            int nr= r + dr[i];
            int nc= c + dc[i];
            
            // check boundary
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            
            // check same character
            if(grid[nr][nc] != grid[r][c]) continue;
            
            // if not visited → explore
            if(!vis[nr][nc]) {
                if(dfs(nr, nc, r, c, grid)) return true;
            }
            // if visited and not parent → cycle found
            else if(nr != pr || nc != pc) {
                return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vis.assign(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) if(dfs(i, j, -1, -1, grid)) return true;
            }
        }
        return false;
    }
};