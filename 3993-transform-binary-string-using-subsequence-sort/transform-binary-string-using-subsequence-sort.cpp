class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        int totalOnes = 0;
        for (char c : s) {
            if (c == '1')
                totalOnes++;
        }

        vector<bool> ans;

        for (string t : strs) {

            int fixedOnes = 0;
            int question = 0;

            for (char c : t) {
                if (c == '1')
                    fixedOnes++;
                else if (c == '?')
                    question++;
            }

            // Number of ? that must become 1
            int needed = totalOnes - fixedOnes;

            if (needed < 0 || needed > question) {
                ans.push_back(false);
                continue;
            }

            // Put 1s in the rightmost ? positions
            for (int i = n - 1; i >= 0; i--) {
                if (t[i] == '?' && needed > 0) {
                    t[i] = '1';
                    needed--;
                }
            }

            // Remaining ? become 0
            for (int i = 0; i < n; i++) {
                if (t[i] == '?')
                    t[i] = '0';
            }

            // Check prefix condition
            int onesS = 0;
            int onesT = 0;
            bool possible = true;

            for (int i = 0; i < n; i++) {

                if (s[i] == '1')
                    onesS++;

                if (t[i] == '1')
                    onesT++;

                if (onesT > onesS) {
                    possible = false;
                    break;
                }
            }

            ans.push_back(possible);
        }

        return ans;
    }
};