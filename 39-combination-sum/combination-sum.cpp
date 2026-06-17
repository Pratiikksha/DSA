class Solution {
public:
    void findCombination(int idx,int curr,vector<int>&temp,vector<int>&candidates,int target, vector<vector<int>>& ans){
        if(idx==candidates.size()){
            if(curr==target){
                ans.push_back(temp);
            }
            return;
        }
        if(curr+candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            findCombination(idx,curr+candidates[idx],temp,candidates,target,ans);
            temp.pop_back();
        }
        findCombination(idx+1,curr,temp,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=accumulate(candidates.begin(),candidates.end(),0);
        vector<vector<int>>ans;
        int curr=0;
        vector<int>temp;
        findCombination(0,curr,temp,candidates,target,ans);
        return ans;
    }
};