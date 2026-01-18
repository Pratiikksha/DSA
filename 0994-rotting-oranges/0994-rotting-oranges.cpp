class Solution {
public:
    void bfs(queue<pair<int, int>>& q, int& fresh,
             vector<vector<int>>& grid, int& time,int m,int n) {     
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            time += 1;
            for (int i = 0; i < sz; i++) {
                auto [a, b] = q.front();
                q.pop();
                int dr[4] = {-1, 0, 1, 0};
                int dc[4] = {0, -1, 0, 1};
                for (int j = 0; j < 4; j++) {
                    int nrow = a + dr[j];
                    int ncol = b + dc[j];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        fresh--;
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int time = 0;
        bfs(q, fresh, grid, time,m,n);
        if (fresh > 0)
            return -1;
        else
            return time;
    }
};