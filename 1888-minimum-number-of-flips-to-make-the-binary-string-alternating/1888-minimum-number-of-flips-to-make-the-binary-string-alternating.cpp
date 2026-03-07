class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n == 1)
            return 0;
        s = s + s;
        string alt1 = "";
        string alt2 = "";
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                alt1 += '1';
                alt2 += '0';
            } else {
                alt1 += '0';
                alt2 += '1';
            }
        }
        int l = 0;
        int x = 0;
        int y = 0;
        int c = INT_MAX;
        for (int r = 0; r < n * 2; r++) {
            if (alt1[r] != s[r]) {
                x++;
            }
            if (alt2[r] != s[r]) {
                y++;
            }
            if (r - l + 1 > n) {
                if (alt1[l] != s[l]) {
                    x--;
                }
                if (alt2[l] != s[l]) {
                    y--;
                }
                l++;
            }
            if (r - l + 1 == n) {
                c = min(c, min(x, y));
            }
        }
        return c;
    }
};