class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxi=0;
        for(int i=1;i<n;i++){
            int profit=prices[i]-mini;
            mini=min(mini,prices[i]);
            maxi=max(maxi,profit);
        }
        return maxi;
    }
};