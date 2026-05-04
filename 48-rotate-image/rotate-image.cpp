class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int k;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                k = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = k;
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};