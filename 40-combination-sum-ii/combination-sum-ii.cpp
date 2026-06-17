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
            findCombination(idx+1,curr+candidates[idx],temp,candidates,target,ans);
            temp.pop_back();
        }
        while(idx<candidates.size()-1 && candidates[idx+1]==candidates[idx]) idx++;
        findCombination(idx+1,curr,temp,candidates,target,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        int curr=0;
        vector<int>temp;
        findCombination(0,curr,temp,candidates,target,ans);
        return ans;
    }
};