class Solution {
public:
    bool safe(int x, int y, int m, int n) {
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            int x = top.first;
            int y = top.second;

            vis[x][y] = true;
            if(x == m-1 && y == n-1) return true;

            // go right
            if(grid[x][y] == 1 || grid[x][y] == 4 || grid[x][y] == 6) {
                // only 3, 5, 1 should be there on right side 
                if(safe(x, y+1, m, n) && (grid[x][y+1] == 3 || grid[x][y+1] == 5 || grid[x][y+1] == 1) && !vis[x][y+1]) q.push({x, y+1}); 
            }
            // go down
            if(grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4) {
                if(safe(x+1, y, m, n) && (grid[x+1][y] == 2 || grid[x+1][y] == 5 || grid[x+1][y] == 6) && !vis[x+1][y]) q.push({x+1, y}); 
            }
            // go left
            if(grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 5) {
                if(safe(x, y-1, m, n) && (grid[x][y-1] == 1 || grid[x][y-1] == 4 || grid[x][y-1] == 6) && !vis[x][y-1]) q.push({x, y-1}); 
            }
            // go up
            if(grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6) {
                if(safe(x-1, y, m, n) && (grid[x-1][y] == 2 || grid[x-1][y] == 3 || grid[x-1][y] == 4) && !vis[x-1][y]) q.push({x-1, y}); 
            }
        }
        return false;
    }
};