class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        // suf[i] = max chars of word2 (from the back) matchable as subsequence in word1[i..n1-1]
        // vector<int> suf(n1 + 1, 0);
        // int j = n2;
        // for (int i = n1 - 1; i >= 0; i--) {
        //     suf[i] = suf[i + 1];
        //     if (j > 0 && word1[i] == word2[j - 1]) {
        //         j--;
        //         suf[i] = suf[i + 1] + 1; // recompute properly below
        //     }
        // }
        // Redo suf cleanly: suf[i] = number of matched suffix chars achievable from word1[i:]
        int j = n2;
        vector<int> suf2(n1 + 1, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            suf2[i] = suf2[i + 1];
            if (j > 0 && word1[i] == word2[j - 1]) {
                j--;
                suf2[i] = n2 - j;
            }
        }

        vector<int> ans;
        bool used = false;
        int jj = 0;
        for (int i = 0; i < n1 && jj < n2; i++) {
            if (word1[i] == word2[jj]) {
                ans.push_back(i);
                jj++;
            } else if (!used && suf2[i + 1] >= n2 - jj - 1) {
                ans.push_back(i);
                jj++;
                used = true;
            }
        }
        if ((int)ans.size() == n2) return ans;
        return {};
    }
};