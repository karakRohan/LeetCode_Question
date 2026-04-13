class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0; // Stores the number of connected components
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){ 

                if(grid[r][c] == '0'){
                    // it is water body
                    continue;
                }

                // new unvisited land piece, i.e. new Connected Component
                cc++; // Connected Component
                queue<pair<int, int> > qu;
                qu.push({r, c}); // store the source node
                grid[r][c] = '0'; // mark it visited

                while(not qu.empty()){
                    auto curr = qu.front(); // get one node from queue
                    qu.pop();

                    // go to all unvisited neighbours of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;

                    // check up
                    if (currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1') {
                        qu.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }

                    // check down
                    if (currRow + 1 < rows && grid[currRow + 1][currCol] == '1') {
                        qu.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }

                    // check left
                    if (currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1') {
                        qu.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = '0';
                    }

                    // check right
                    if (currCol + 1 < cols && grid[currRow][currCol + 1] == '1') {
                        qu.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = '0';
                    }
                }
            }
        }
        return cc;
    }
};