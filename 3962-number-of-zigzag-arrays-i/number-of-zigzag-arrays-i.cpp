class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);

        // length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> nxtUp(m + 1), nxtDown(m + 1);

            long long pref = 0;

            // nxtUp[x] = sum down[v] for v < x
            for (int x = 1; x <= m; x++) {
                nxtUp[x] = pref;
                pref += down[x];
                pref %= MOD;
            }

            long long suff = 0;

            // nxtDown[x] = sum up[v] for v > x
            for (int x = m; x >= 1; x--) {
                nxtDown[x] = suff;
                suff += up[x];
                suff %= MOD;
            }

            up.swap(nxtUp);
            down.swap(nxtDown);
        }

        long long ans = 0;

        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
            ans %= MOD;
        }

        return (int)ans;
    }
};