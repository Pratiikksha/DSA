class Solution {
public:
    int lcs(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].size() != words[j].size() &&
                    words[i].size() == words[j].size() + 1 &&
                    words[j].size() == lcs(words[i], words[j]) &&
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};