class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        // Run BFS from every node
        for (int start = 0; start < n; start++) {

            vector<int> dist(n, -1);
            vector<int> parent(n, -1);

            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {

                    // First time visiting this node
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        parent[nei] = node;
                        q.push(nei);
                    }
                    // Found a cycle
                    else if (parent[node] != nei) {
                        ans = min(ans, dist[node] + dist[nei] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};