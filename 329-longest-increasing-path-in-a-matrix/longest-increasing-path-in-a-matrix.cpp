class Solution {
public:
    int m, n;

    int dfs(int x, int y, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        if (dp[x][y] != -1)
            return dp[x][y];

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        int best = 1;

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                matrix[nx][ny] > matrix[x][y]) {

                best = max(best, 1 + dfs(nx, ny, matrix, dp));
            }
        }

        return dp[x][y] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};