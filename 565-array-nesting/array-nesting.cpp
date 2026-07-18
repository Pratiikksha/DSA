class Solution {
public:
    void dfs(int i, vector<int>& nums, int &cnt, vector<int>& vis){
        if(i>=nums.size() || vis[i]) return;
        cnt++;
        vis[i]=1;
        dfs(nums[i],nums,cnt,vis);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            if(!vis[i])
            dfs(i,nums,cnt,vis);
            maxi=max(maxi,cnt);
        }
        return maxi;
     }
};