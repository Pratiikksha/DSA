class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        int front = 1;

        // Diagonals starting from first column
        for (int i = 0; i < m; i++) {
            int row = i;
            int col = 0;

            vector<int> temp;

            while (row >= 0 && col < n) {
                temp.push_back(mat[row][col]);
                row--;
                col++;
            }

            if (!front)
                reverse(temp.begin(), temp.end());

            for (int x : temp)
                ans.push_back(x);

            front = !front;
        }

        // Diagonals starting from last row
        for (int i = 1; i < n; i++) {
            int row = m - 1;
            int col = i;

            vector<int> temp;

            while (row >= 0 && col < n) {
                temp.push_back(mat[row][col]);
                row--;
                col++;
            }

            if (!front)
                reverse(temp.begin(), temp.end());

            for (int x : temp)
                ans.push_back(x);

            front = !front;
        }

        return ans;
    }
};