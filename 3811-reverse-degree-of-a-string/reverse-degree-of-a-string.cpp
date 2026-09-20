class Solution {
public:
    int reverseDegree(string s) {
        int res = 0, acc = 0;
        for (int i = s.size() - 1; i >= 0; i--)
            res += acc += '{' - s[i];

        return res;
    }
};