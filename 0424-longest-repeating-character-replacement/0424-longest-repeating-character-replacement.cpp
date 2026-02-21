class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int maxF = 0;
        int left = 0;
        int n = s.size();
        int len = 0;
        int maxLen = 0;
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++;
            maxF = max(maxF, freq[s[right] - 'A']);
            int winLen = right - left + 1;
            while (winLen - maxF > k) {
                freq[s[left] - 'A']--;
                left++;
                winLen = right - left + 1;
            }
            len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};