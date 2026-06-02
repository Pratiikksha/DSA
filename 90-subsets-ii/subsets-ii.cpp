class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans) {
        ans.push_back(curr);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0, nums, curr, ans);
        return ans;
    }
};