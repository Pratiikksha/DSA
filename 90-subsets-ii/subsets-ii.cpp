class Solution {
public:
    void subset(int idx, vector<int>& curr, vector<int>& nums,
                vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            subset(i + 1, curr, nums, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        subset(0, curr, nums, ans);
        return ans;
    }
};