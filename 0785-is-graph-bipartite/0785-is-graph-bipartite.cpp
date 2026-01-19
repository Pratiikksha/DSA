class Solution {
public:
    bool bfs(int num, vector<vector<int>>& graph, vector<int>& vis) {
    vis[num] = 0;
    queue<int> q;
    q.push(num);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto adjNode : graph[node]) {
            if (vis[adjNode] == -1) {
                vis[adjNode] = !vis[node];
                q.push(adjNode);
            } else if (vis[adjNode] == vis[node]) {
                return false;
            }
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!bfs(i, graph, vis))
                    return false;
            }
        }
        return true;
    }
};