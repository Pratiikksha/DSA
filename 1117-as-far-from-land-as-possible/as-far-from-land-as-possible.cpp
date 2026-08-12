class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int flag1 = false;
        int flag0 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                    flag1 = true;
                    vis[i][j] = 1;
                } else {
                    flag0 = true;
                }
            }
        }
        if (!(flag1 & flag0))
            return -1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && !vis[nx][ny]) {
                    if (dist[x][y] + 1 < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, dist[i][j]);
            }
        }
        return maxi;
    }
}
;