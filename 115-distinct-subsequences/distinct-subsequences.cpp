class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = t.size();
        int n2 = s.size();
        vector<vector<unsigned long long>> dp(n1+1, vector<unsigned long long>(n2+1, 0));
        for (int j = 0; j <= n2; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return (int)dp[n1][n2];
    }
};