class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board, int m, int n) {
        board[x][y] = '#';
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                dfs(nx, ny, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(0, i, board, m, n);
            }
            if (board[m - 1][i] == 'O') {
                dfs(m - 1, i, board, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0, board, m, n);
            }
            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1, board, m, n);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};