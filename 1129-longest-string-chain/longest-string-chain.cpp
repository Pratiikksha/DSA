class Solution {
public:
    bool check(string& a, string& b) {
        if (a.size() != b.size() + 1)
            return false;

        int i = 0, j = 0;
        while (i < a.size()) {
            if (j < b.size() && a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == b.size();
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
                if (check(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};