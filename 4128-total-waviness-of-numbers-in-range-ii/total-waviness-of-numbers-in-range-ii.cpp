class Solution {
public:
    struct Node {
        long long cnt;
        long long wave;
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev1, int prev2, bool started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev1][prev2][started]) {
            return dp[pos][prev1][prev2][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool newTight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, newTight);

                ans.cnt += nxt.cnt;
                ans.wave += nxt.wave;
            }
            else if (!started) {
                Node nxt = dfs(pos + 1, 10, d, true, newTight);

                ans.cnt += nxt.cnt;
                ans.wave += nxt.wave;
            }
            else {
                int add = 0;

                if (prev1 != 10) {
                    if ((prev2 > prev1 && prev2 > d) ||
                        (prev2 < prev1 && prev2 < d)) {
                        add = 1;
                    }
                }

                Node nxt = dfs(pos + 1, prev2, d, true, newTight);

                ans.cnt += nxt.cnt;
                ans.wave += nxt.wave + add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][prev1][prev2][started] = true;
            dp[pos][prev1][prev2][started] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};