class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& image, int color) {
        int m = image.size();
        int n = image[0].size();
        int original = image[row][col];
        if (original == color)
            return;
        image[row][col] = color;
        queue<pair<int, int>> q;
        q.push({row, col});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = a + dr[i];
                int ncol = b + dc[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && nrow < n &&
                    image[nrow][ncol] == original) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        bfs(sr, sc, image, color);
        return image;
    }
};