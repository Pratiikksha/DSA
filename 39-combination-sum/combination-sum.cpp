class Solution {
public:
    void sum(int idx,int target,vector<int>& curr,vector<vector<int>>& ans,vector<int>& nums){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(idx==nums.size()){
            return;
        }
        curr.push_back(nums[idx]);
        if(target>=nums[idx])
        sum(idx,target-nums[idx],curr,ans,nums);
        // if(target>=nums[idx])
        // sum(idx+1,target-nums[idx],curr,ans,nums);
        curr.pop_back();
        sum(idx+1,target,curr,ans,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sum(0,target,curr,ans,candidates);
        return ans;
    }
};