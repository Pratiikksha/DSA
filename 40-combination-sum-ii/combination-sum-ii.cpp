class Solution {
public:
    void solve(int idx, int target, vector<int>& curr, vector<vector<int>>& ans,
               vector<int>& nums) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicates
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > target)
                break;

            curr.push_back(nums[i]);

            solve(i + 1, target - nums[i], curr, ans, nums);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, target, curr, ans, candidates);

        return ans;
    }
};