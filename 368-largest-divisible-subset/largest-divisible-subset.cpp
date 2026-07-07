class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> backTrack(n, 0);
        int maxIndex = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            backTrack[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j]==0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    backTrack[i] = j;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                maxIndex = i;
            }
        }
        int curr = maxIndex;
        vector<int> temp;
        while (curr != backTrack[curr]) {
            temp.push_back(nums[curr]);
            curr = backTrack[curr];
        }
        temp.push_back(nums[curr]);
        return temp;
    }
};