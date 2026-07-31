class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            vis[i][0] = vis[i][n - 1] = 1;
        }
        for (int i = 1; i < n - 1; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});
            vis[0][i] = vis[m - 1][i] = 1;
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int trapped = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int x = it.second.first;
            int y = it.second.second;
            int h = it.first;
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                trapped += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }
        return trapped;
    }
};