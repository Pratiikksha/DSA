class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &[next, time] : adj[node]) {
                long long nd = d + time;

                if (nd < dist[next]) {
                    dist[next] = nd;
                    ways[next] = ways[node];
                    pq.push({nd, next});
                }
                else if (nd == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
