class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i:nums){
            sum+=i;
        }
        if(sum%k!=0) return false;
        int target=sum/k;
        for(int i:nums){
            if(i>target) return false;
        }
        int totalWays= 1<<n; 
        vector<int>dp(totalWays, false);
        dp[0]=true;
        vector<int>currSum(totalWays, 0);

        for(int mask=0;mask<totalWays;mask++){
            if(dp[mask]==false){
                continue;
            }
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    continue;
                }
                int newSum= currSum[mask]+nums[i];
                if(newSum>target){
                    continue;
                }
                int newMask=mask | (1<<i);
                dp[newMask]=true;
                currSum[newMask]= newSum%target;
            }
        }
        return dp[totalWays-1];
    }
};