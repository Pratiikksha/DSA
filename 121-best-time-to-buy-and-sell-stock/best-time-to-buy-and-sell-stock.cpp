class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxi=0;
        for(int i=1;i<n;i++){
            maxi=max(maxi,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return max(maxi,prices[n-1]-mini);
    }
};