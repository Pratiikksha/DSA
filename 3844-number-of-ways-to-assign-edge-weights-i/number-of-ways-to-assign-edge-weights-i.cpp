class Solution {
public:
    static constexpr long long mod = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = (ans * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }

    void height(int node, int parent,
                vector<vector<int>>& adj,
                int depth, int& maxi) {

        maxi = max(maxi, depth);

        for (int nei : adj[node]) {
            if (nei != parent)
                height(nei, node, adj, depth + 1, maxi);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxi = 0;

        height(1, 0, adj, 0, maxi);

        return power(2, maxi - 1);
    }
};