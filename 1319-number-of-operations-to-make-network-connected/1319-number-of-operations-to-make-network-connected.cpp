class Solution {
public:
    void dfs(int num, vector<vector<int>>& adj, vector<int>& vis) {
        vis[num] = 1;
        for (auto adjNode : adj[num]) {
            if (!vis[adjNode]) {
                dfs(adjNode, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int k = connections.size();
        vector<vector<int>> adj(n);
        if (k < n - 1)
            return -1;
        for (int i = 0; i < k; i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        if (k < count - 1)
            return -1;
        else
            return count - 1;
    }
};