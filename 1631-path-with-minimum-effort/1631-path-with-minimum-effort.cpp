class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int effort = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if (row == m - 1 && col == n - 1)
                return effort;

            if (effort > dis[row][col]) continue;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n) {

                    int newEffort = max(
                        effort,
                        abs(heights[nrow][ncol] - heights[row][col])
                    );

                    if (newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
