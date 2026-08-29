class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int k;

    pair<long long, long long> dfs(int u, int parent) {
        long long base = 0;
        vector<long long> gain;

        for (auto [v, w] : adj[u]) {
            if (v == parent) continue;

            auto [a, b] = dfs(v, u);

            // If we don't take edge (u,v), child contributes a
            base += a;

            // If we take edge (u,v), child contributes b + w
            // compared to not taking it: gain = w + b - a
            long long d = w + b - a;

            if (d > 0) {
                gain.push_back(d);
            }
        }

        // Take the largest gains first
        sort(gain.rbegin(), gain.rend());

        long long a = base;  // u can take at most k edges
        long long b = base;  // u can take at most k-1 edges

        // State b: at most k-1 children
        for (int i = 0; i < min((int)gain.size(), k - 1); i++) {
            b += gain[i];
        }

        // State a: at most k children
        for (int i = 0; i < min((int)gain.size(), k); i++) {
            a += gain[i];
        }

        return {a, b};
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        this->k=k;
        adj.resize(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return dfs(0, -1).first;
    }
};