class Solution {
public:
    void solve(int idx,int target,int k, vector<int>&curr, vector<vector<int>>&ans,vector<int>&nums){
        if(curr.size()==k && target==0){
            ans.push_back(curr);
            return ;
        }
        if(idx==nums.size()) return;
        if(nums[idx]<=target){
        curr.push_back(nums[idx]);
        solve(idx+1,target-nums[idx],k,curr,ans,nums);
        curr.pop_back();
        }
        solve(idx+1,target,k,curr,ans,nums);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>9) return {};
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,n,k,curr,ans,nums);
        return ans;
    }
};