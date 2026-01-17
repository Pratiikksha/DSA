class Solution {
public:
    void bfs(int sr, int sc, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nrow = row + delRow[d];
                int ncol = col + delCol[d];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0) {

                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]=='1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};