class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result; // to store the final result

    bool canPlaceQueen(int row, int col, int n){
        // column check
        for(int i = row-1; i>= 0; i--){
            if(grid[i][col] == 'Q') return false; // we are attacked
        }
        // left diagonal check
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
            if(grid[i][j] == 'Q') return false; // we are attacked
        }
        // right diagonal check
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(grid[i][j] == 'Q') return false; // we are attacked
        }
        return true;  // no attack found
    }

    // backtracking function
    void f(int row, int n){
        // base case
        if(row == n){
            vector<string> temp;

            for(int i=0; i<n; i++){
                string res = "";
                for(int j=0; j<n; j++){
                    res += grid[i][j];
                }
                temp.push_back(res);
            }

            result.push_back(temp);
            return;
        }

        for(int col=0; col<n; col++){
            if(canPlaceQueen(row, col, n)){
                grid[row][col] = 'Q';
                f(row+1, n);
                grid[row][col] = '.'; // backtracking step
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n, vector<char>(n, '.')); // initialize grid

        f(0, n); // start from row 0
        return result;
    }
};