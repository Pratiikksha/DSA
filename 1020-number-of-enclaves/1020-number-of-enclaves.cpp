class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int m, int n) {
        vis[row][col] = 1;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                grid[nrow][ncol]=0;
                dfs(nrow, ncol, grid, vis, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector(n, 0));
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, vis, m, n);
            if (grid[i][n - 1] == 1)
                dfs(i, n-1, grid, vis, m, n);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1)
                dfs(0, i, grid, vis, m, n);
            if (grid[m - 1][i] == 1)
                dfs(m-1, i, grid, vis, m, n);
        }
        int cnt=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] ==1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};