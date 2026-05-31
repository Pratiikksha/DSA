class Solution {
public:
//    bool knap(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){
//     if(target==0) return true;
//     if(idx==0) return false;
//     if(dp[idx][target]!=-1) return dp[idx][target]; 
//     bool take=false;
//     if(nums[idx]<=target)
//     take=knap(idx-1,target-nums[idx],nums,dp);
//     bool not_take=knap(idx-1,target,nums,dp);
//     return dp[idx][target]=take||not_take;
//    }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
//         if(sum%2!=0){
//             return false;
//         }
//         int target=sum/2;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return knap(n-1,target,nums,dp);
//     }
bool canPartition(vector<int>& nums){
    int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=target)
        dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<target+1;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(j>=nums[i])
                take=dp[i-1][j-nums[i]];
                dp[i][j]=take||not_take;
            }
        }
        return dp[n-1][target];
}
};