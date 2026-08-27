class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // Try to make the answer greater at position i.
        // We go from right to left so that the first
        // difference happens as late as possible.
        for (int i = n - 1; i >= 0; i--) {

            // We need target[0...i-1] to be exactly matched.
            vector<int> freq = cnt;
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            // At position i, find smallest character
            // strictly greater than target[i].
            int cur = target[i] - 'a';
            int bigger = -1;

            for (int c = cur + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            string ans = target.substr(0, i);

            ans += char('a' + bigger);
            freq[bigger]--;

            // Put remaining characters in smallest order.
            for (int c = 0; c < 26; c++) {
                while (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};