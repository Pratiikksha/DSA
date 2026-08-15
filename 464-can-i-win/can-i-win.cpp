class Solution {
public:
    int maxi;
    int n;

    int solve(int mask, vector<int>& dp) {
        if (dp[mask] != -1)
            return dp[mask];

        int curr = 0;

        for (int i = 1; i <= n; i++) {
            if (mask & (1 << (i - 1))) {
                curr += i;
            }
        }

        for (int i = 1; i <= n; i++) {

            if ((mask & (1 << (i - 1))) == 0) {

                if (curr + i >= maxi)
                    return dp[mask] = 1;

                int newMask = mask | (1 << (i - 1));

                if (!solve(newMask, dp))
                    return dp[mask] = 1;
            }
        }

        return dp[mask] = 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        n = maxChoosableInteger;
        maxi = desiredTotal;

        if (desiredTotal <= n)
            return true;

        int sum = n * (n + 1) / 2;

        if (sum < desiredTotal)
            return false;

        vector<int> dp(1 << n, -1);

        return solve(0, dp);
    }
};