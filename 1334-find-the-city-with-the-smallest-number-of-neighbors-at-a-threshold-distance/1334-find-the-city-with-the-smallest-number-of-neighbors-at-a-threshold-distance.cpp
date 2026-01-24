class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector(n, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u][v] = w;
            adj[v][u] = w;
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        int nw = adj[i][k] + adj[k][j];
                        if (adj[i][j] > nw) {
                            adj[i][j] = nw;
                        }
                    }
                }
            }
        }
        int c = 0;
        int count = INT_MAX, num = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold) {
                    c++;
                }
            }
            count = min(count, c);
            if (count == c) {
                num = i;
            }
            c = 0;
        }
        return num;
    }
};