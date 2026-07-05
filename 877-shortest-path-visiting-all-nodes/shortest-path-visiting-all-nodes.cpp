class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int full_state = (1 << n) - 1;
        vector<vector<int>> dp(1 << n,
                               vector<int>(n, INT_MAX)); // dp[state][last];
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            int init = 1 << i;
            dp[init][i] = 0;
            q.push({init, i});
        }
        while (!q.empty()) {
            auto [state, u] = q.front();
            q.pop();
            for (int v : graph[u]) {
                int newState = state | (1 <<v);
                if (dp[newState][v] > dp[state][u] + 1) {
                    dp[newState][v] = dp[state][u] + 1;
                    q.push({newState, v});
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[full_state][i]);
        }
        return mini;
    }
};