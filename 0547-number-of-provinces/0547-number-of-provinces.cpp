class Solution {
public:
    void dfs(int k, vector<int>& visited, vector<vector<int>>& adj) {
        visited[k] = 1;
        for (auto it : adj[k]) {
            if (!visited[it]) {
                dfs(it, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        vector<int> visited(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces += 1;
                dfs(i, visited, adj);
            }
        }
        return provinces;
    }
};