class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> ans(r, vector<int>(c));

        int total = r * c;
        k %= total;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {

                int idx = i * c + j;
                int newIdx = (idx + k) % total;

                int nr = newIdx / c;
                int nc = newIdx % c;

                ans[nr][nc] = grid[i][j];
            }
        }

        return ans;
    }
};