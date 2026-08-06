class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            int idxL = lower_bound(nums.begin()+i+1, nums.end(), l) - nums.begin();
            int idxR = lower_bound(nums.begin()+i+1, nums.end(), r + 1) - nums.begin();
           
            ans += (idxR - idxL);

        }
        return ans;
    }
};