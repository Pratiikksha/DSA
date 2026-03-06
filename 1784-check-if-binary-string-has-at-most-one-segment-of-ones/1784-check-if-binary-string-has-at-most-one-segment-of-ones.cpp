class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        if (n == 0)
            return false;
        if (n == 1)
            return (s[0] == '1');
        int k = -1;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                k = i;
                break;
            }
        }
        if (k == -1)
            return true;
        for (int i = k + 1; i < n; i++) {
            if (s[i] == '1') {
                return false;
            }
        }
        return true;
    }
};