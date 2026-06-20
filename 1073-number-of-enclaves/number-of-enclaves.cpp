class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;

        return 1 +
               dfs(r + 1, c, grid) +
               dfs(r - 1, c, grid) +
               dfs(r, c + 1, grid) +
               dfs(r, c - 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalLand = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    totalLand++;
            }
        }

        int boundaryLand = 0;

        // First and last column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                boundaryLand += dfs(i, 0, grid);

            if (grid[i][n - 1] == 1)
                boundaryLand += dfs(i, n - 1, grid);
        }

        // First and last row
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                boundaryLand += dfs(0, j, grid);

            if (grid[m - 1][j] == 1)
                boundaryLand += dfs(m - 1, j, grid);
        }

        return totalLand - boundaryLand;
    }
};