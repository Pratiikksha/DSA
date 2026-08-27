class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        queue<pair<int, int>> q;
        if (grid[0][0])
            return -1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        q.push({0, 0});
        int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
        int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
        while (!q.empty()) {
            int size = q.size();
            cnt++;
            while (size--) {
                auto [x, y] = q.front();
                if (x == n - 1 && y == n - 1)
                    return cnt;
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < n && ny < n && nx >= 0 && ny >= 0 &&
                        grid[nx][ny] == 0 && !vis[nx][ny]) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        return -1;
    }
};