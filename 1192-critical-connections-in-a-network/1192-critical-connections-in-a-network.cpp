class Solution {
public:
    int timer = 1;
    void dfs(vector<vector<int>>& adj, int num, int parent, int low[],
             int time[], vector<int>& vis, vector<vector<int>>& bridges) {
        vis[num] = 1;
        time[num] = low[num] = timer++;
        for (auto adjNode : adj[num]) {
            if (adjNode == parent)
                continue;
            if (!vis[adjNode]) {
                dfs(adj, adjNode, num, low, time, vis, bridges);
                low[num] = min(low[num], low[adjNode]);
                if (low[adjNode] > time[num]) {
                    bridges.push_back({adjNode, num});
                }
            } else {
                low[num] = min(low[num], time[adjNode]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        int low[n], time[n];
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, i, -1, low, time, vis, bridges);
            }
        }

        return bridges;
    }
};