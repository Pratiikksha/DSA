class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> values(nums.begin(), nums.end());

        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int val : values) {
            for (int cnt = 0; cnt < 3; cnt++) {
                vector<bool> next = dp[cnt + 1];

                for (int x = 0; x < MAXX; x++) {
                    if (dp[cnt][x])
                        next[x ^ val] = true;
                }

                dp[cnt + 1] = move(next);
            }
        }

        int ans = 0;
        for (bool ok : dp[3])
            ans += ok;

        return ans;
    }
};