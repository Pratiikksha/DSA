class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int j = 1; j <k+1 ; j++) {
                    int profit = 0;
                    if (buy) {
                        profit =
                            max(-prices[i] + dp[i+1][!buy][j], dp[i+1][buy][j]);
                    } else {
                        profit =
                            max(prices[i] + dp[i+1][!buy][j - 1], dp[i+1][buy][j]);
                    }
                    dp[i][buy][j]=profit;
                }
            }
        }
        return dp[0][1][k];  
    }
};