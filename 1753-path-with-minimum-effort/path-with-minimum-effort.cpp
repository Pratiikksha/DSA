class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = 0;
        q.push({0, {0, 0}});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int d = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < row && nx >= 0 && ny < col && ny >= 0) {
                    int effort = abs(heights[x][y] - heights[nx][ny]);
                    int newEffort = max(d, effort);
                    if (newEffort < dis[nx][ny]) {
                        dis[nx][ny] = newEffort;
                        q.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return dis[row - 1][col - 1];
    }
};