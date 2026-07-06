class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        // vector<vector<int>>dp(n+2,(vector<int>(2,0)));
        vector<int>curr(2,0);
        vector<int>after(2,0);
        vector<int>after2(2,0);
        after[1]=0;
        after[0]=0;
        for(int i=n-1;i>=0;i--){
            int  profit=0;
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    profit=max(-prices[i]+after[!buy],after[buy]);
                }
                else{
                    profit=max(prices[i]+after2[!buy],after[buy]);
                }
                curr[buy]=profit;
                after2=after;
                after=curr;
            }
        }
        return curr[1]; 
    }
};