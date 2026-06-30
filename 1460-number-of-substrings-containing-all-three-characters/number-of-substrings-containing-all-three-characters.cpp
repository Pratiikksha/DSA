class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        if (n <= 2)
            return 0;
        int a = 0, b = 0, c = 0;
        int l = 0;
        int r = 0;
        int count=0;
        while (r < n) {
            if (s[r] == 'a')
                a++;
            if (s[r] == 'b')
                b++;
            if (s[r] == 'c')
                c++;
            while (a >= 1 && b >= 1 && c >= 1 && l<=r) {
                if (s[l] == 'a')
                    a--;
                if (s[l] == 'b')
                    b--;
                if (s[l] == 'c')
                    c--;
                l++;
            }
            count+=l;
            r++;
        }
        return count;
    }
};