class Solution {
    public int maxProfit(int[] prices) {
        int mini=100000;
        int ans=0;
        int n=prices.length;
        for(int i=0;i<n;i++){
            mini=Math.min(mini,prices[i]);
            ans=Math.max(prices[i]-mini,ans);
        }
        return ans;
    }
}