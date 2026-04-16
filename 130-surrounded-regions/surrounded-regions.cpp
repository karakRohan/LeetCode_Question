class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& board)
    {
        if( i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] == 1 || board[i][j] == 'X' ) return ;
        visited[i][j] = 1;
        dfs(i-1,j,visited,board);
        dfs(i+1,j,visited,board);
        dfs(i,j+1,visited,board);
        dfs(i,j-1,visited,board);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    if(board[i][j] == 'O')
                    dfs(i,j,visited,board);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j] == 0 && board[i][j] == 'O') board[i][j]='X';
            }
        }
    }
};