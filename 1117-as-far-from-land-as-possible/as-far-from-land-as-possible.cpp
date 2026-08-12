class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        // vector<vector<int>> dist(n, vector<int>(n, 1e9));
        int ans = INT_MAX;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int flag1 = false;
        int flag0 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
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
         ans = -1;

        while (!q.empty()) {
            int sz = q.size();
            ans++;

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        grid[nx][ny] == 0) {

                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};