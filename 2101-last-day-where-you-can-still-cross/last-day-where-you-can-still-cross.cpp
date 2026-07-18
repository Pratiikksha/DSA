class Solution {
public:
    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {

        // 0 = land, 1 = water
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood first 'day' cells
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;

        vector<vector<int>> vis(row, vector<int>(col, 0));

        // Start BFS from every land cell in top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while (!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            if (r == row - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= row || nc < 0 || nc >= col)
                    continue;

                if (vis[nr][nc])
                    continue;

                if (grid[nr][nc])
                    continue;

                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int low = 0;
        int high = cells.size();
        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canCross(mid, row, col, cells)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};