class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+2);
        arr[0]=1;
        arr[n+1]=1;
        for(int i=0;i<n;i++){
            arr[i+1]=nums[i];
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int len=1;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    int coins=dp[i][k-1]+dp[k+1][j]+ arr[i-1]*arr[j+1]*arr[k];
                    dp[i][j]=max(dp[i][j],coins);
                }
            }
        }
        return dp[1][n];
    }
};