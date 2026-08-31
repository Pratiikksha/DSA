class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;

        for (auto &[diagonal, v] : mp) {
            reverse(v.begin(), v.end());

            for (int x : v) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};