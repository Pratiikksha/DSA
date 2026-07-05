class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                string w1 = words[i], w2 = words[j];
                int n1 = words[i].size();
                int n2 = words[j].size();
                for (int k = 1; k <= min(n1, n2); k++) {
                    if (w1.substr(n1 - k) == w2.substr(0, k)) {
                        overlap[i][j] = k;
                    }
                }
            }
        }

        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            dp[1 << i][i] = words[i].size();
        for (int state = 0; state < (1 << n); state++) {
            for (int u = 0; u < n; u++) {
                if (dp[state][u] == INT_MAX)
                    continue;
                for (int v = 0; v < n; v++) {
                    if (u == v || (state & (1 << v)))
                        continue;
                    int newState = state | (1 << v);
                    int newCost =
                        dp[state][u] + (words[v].size() - overlap[u][v]);
                    if (dp[newState][v] > newCost) {
                        dp[newState][v] = newCost;
                        parent[newState][v] = u;
                    }
                }
            }
        }
        int full_state = (1 << n) - 1;
        int mini = INT_MAX;
        int end = -1;
        for (int i = 0; i < n; i++) {
            if (mini > dp[full_state][i]) {
                mini = dp[full_state][i];
                end = i;
            }
        }
        vector<int> order;

        int mask = full_state;
        while (end != -1) {
            order.push_back(end);
            int p = parent[mask][end];
            mask ^= (1 << end);
            end = p;
        }

        reverse(order.begin(), order.end());

        string ans = words[order[0]];

        for (int i = 1; i < order.size(); i++) {
            int u = order[i - 1];
            int v = order[i];
            ans += words[v].substr(overlap[u][v]);
        }
        return ans;
    }
};