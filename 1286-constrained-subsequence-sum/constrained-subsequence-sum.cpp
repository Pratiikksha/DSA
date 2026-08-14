class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        if(mx<=0) return mx;
        int n=nums.size();
        vector<int>dp(n,0);
        int ans=0;
        deque<int>dq;
        dq.push_back(0);
        for(int i=0;i<n;i++){
            int maxi=0;
            // for(int j=max(0,i-k);j<=i-1;j++){
            //     maxi=max(maxi,dp[j]);
            // 
            // }
            while(!dq.empty() && dq.front()<i-k){
                dq.pop_front();
            }
            dp[i]=max(nums[i],dp[dq.front()]+nums[i]);
            while(!dq.empty() && dp[dq.back()]<dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};