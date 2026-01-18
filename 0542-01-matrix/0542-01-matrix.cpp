class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis,
             vector<vector<int>>& dis, queue<pair<pair<int, int>, int>>& q,int m,int n) {
        while (!q.empty()) {
                auto [a, b] = q.front().first;
                int c=q.front().second;
                q.pop();
                int dr[4] = {1, 0, -1, 0};
                int dc[4] = {0, 1, 0, -1};
                dis[a][b]=c;
                for (int j = 0; j < 4; j++) {
                    int row = a + dr[j];
                    int col = b + dc[j];
                    if (row >= 0 && row<m && col >= 0 && col<n &&
                        mat[row][col]==1 && !vis[row][col]) {
                        vis[row][col]=1;
                        q.push({{row,col},c+1});
                    }
                }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        ;
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector(n, 0));
        vector<vector<int>> dis(m, vector(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j]=1;
                    q.push({{i, j}, 0});
                }
            }
        }
        bfs(mat,vis,dis,q,m,n);
        return dis;
    }
};