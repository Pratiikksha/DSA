class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>mp(20000,0);
        for(int i=0;i<n;i++){
            mp[nums[i]]+=nums[i];
        }
        vector<int>dp(20000,0);
        dp[0]=mp[0];
        dp[1]=max(mp[0],mp[1]);
        for(int i=2;i<20000;i++){
            dp[i]=max(dp[i-2]+mp[i],dp[i-1]);
        }
        return dp[19999];
    }
};