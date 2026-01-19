class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis, int m, int n) {
        vis[row][col] = 1;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, board, vis, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector(n, 0));
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board, vis, m, n);
            if (board[i][n-1] == 'O')
                dfs(i, n-1, board, vis, m, n);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                dfs(0, i, board, vis, m, n);
            if (board[m-1][i] == 'O')
                dfs(m-1, i, board, vis, m, n);
        }
        for (int i = 0; i < m; i++) {
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};