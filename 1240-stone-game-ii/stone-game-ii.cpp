class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[i][M]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {

            for(int M = 1; M <= n; M++) {

                // Can take all remaining piles
                if(2 * M >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int ans = 0;

                for(int X = 1; X <= 2 * M; X++) {

                    int nextM = max(M, X);

                    int current =
                        suffix[i] - dp[i + X][nextM];

                    ans = max(ans, current);
                }

                dp[i][M] = ans;
            }
        }

        return dp[0][1];
    }
};