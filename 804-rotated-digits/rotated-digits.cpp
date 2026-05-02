class Solution {
public:
    int rotatedDigits(int n) {
        unordered_set<int> s= {2, 5, 6, 9};
        unordered_set<int> st = {3, 7, 4};
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int k = i;
            bool c = false;
            while (k) {
                int r = k % 10;
                k = k / 10;
                if (st.find(r) != st.end()) {
                    c = false;
                    break;
                }
                if (s.find(r) != s.end()) {
                    c = true;
                }
            }
            if (c)
                count++;
        }
        return count;
    }
};