class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        queue<int> pq;
        int ans = INT_MAX;
        pq.push(1);
        vector<int> vis(n + 1);
        vis[1]=1;
        while (!pq.empty()) {
            int node = pq.front();
            pq.pop();
            for (auto it : adj[node]) {
                ans = min(ans, it.second);
                if (!vis[it.first]) {
                    pq.push(it.first);
                    vis[it.first]=1;
                }
            }
        }
        return ans;
    }
};