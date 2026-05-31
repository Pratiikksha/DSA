class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> value(n, 0);
        int minPrice = INT_MAX;
        int idx = -1;
        vector<int> cost(n, 0), bonus(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
            minPrice = min(minPrice, items[i][1]);
            if (minPrice == items[i][1]) {
                idx = i;
            }
            cost[i] = items[i][1];
            value[i] = bonus[i] + 1;
        }
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int b = budget; b >= cost[i]; b--) {
                if (dp[b - cost[i]] != -1) {
                    dp[b] = max(dp[b], dp[b - cost[i]] + value[i]);
                }
            }
        }
        int ans = budget / minPrice;
        ans += bonus[idx];
        for (int i = 0; i <= budget; i++) {
            if (dp[i] == -1)
                continue;
            int alt = dp[i] + (budget - i) / minPrice;
            ans = max(ans, alt);
        }
        return ans;
    }
};