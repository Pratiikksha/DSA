class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z')
                cur++;
            else if (c == '*')
                cur = max(0LL, cur - 1);
            else if (c == '#')
                cur *= 2;
            else if (c == '%')
                ;   // length unchanged

            len[i] = cur;
        }

        if (k >= cur)
            return '.';

        for (int i = n - 1; i >= 0; i--) {

            long long prevLen = (i == 0 ? 0 : len[i - 1]);
            char c = s[i];

            if ('a' <= c && c <= 'z') {

                if (k == prevLen)
                    return c;

            }
            else if (c == '*') {
                // k unchanged
            }
            else if (c == '#') {

                if (prevLen > 0)
                    k %= prevLen;

            }
            else if (c == '%') {

                k = prevLen - 1 - k;
            }
        }

        return '.';
    }
};