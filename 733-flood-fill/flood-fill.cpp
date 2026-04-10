class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    // The Below Function Will Do DFS From currRow, currCol to it's neighbours containing initial Color
    void dfs(vector<vector<int> > &image, int currRow, int currCol, int initialColor, int newColor){
        int n = image.size(); // total rows
        int m = image[0].size(); // total cols
        if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) {
            return; // you are outside the grid
        }
        // if the cell you landed is not of inital color
        if(image[currRow][currCol] != initialColor) return;

        image[currRow][currCol] = newColor;
        dfs(image, currRow + 1, currCol, initialColor, newColor); // down
        dfs(image, currRow, currCol - 1, initialColor, newColor); // left
        dfs(image, currRow - 1 , currCol, initialColor, newColor); // up
        dfs(image, currRow, currCol + 1, initialColor, newColor); // Right
    }
};