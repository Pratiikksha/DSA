class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,(vector<int>(2,0)));
        // dp[n][1]=0;
        // dp[n][0]=0;
         vector<int>curr(2,0);
        vector<int>after(2,0);
        for(int i=n-1;i>=0;i--){
            int  profit=0;
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    profit=max(-fee-prices[i]+after[!buy],after[buy]);
                }
                else{
                    profit=max(prices[i]+after[!buy],after[buy]);
                }
                curr[buy]=profit;
            }
            after=curr;
        }
        return curr[1];
    }
};