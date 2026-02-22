class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n2 > n1)
            return "";
        unordered_map<char, int> mp1;
        for (auto st : t) {
            mp1[st]++;
        }
        int required = mp1.size();
        unordered_map<char, int> mp2;
        int left = 0;
        int formed = 0;
        int len = 0;
        int minLen = INT_MAX;
        int start;
        for (int right = 0; right < n1; right++) {
            mp2[s[right]]++;
            if (mp1.count(s[right]) && mp2[s[right]] == mp1[s[right]]) {
                formed++;
            }
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }
                mp2[s[left]]--;
                if (mp1.count(s[left]) && mp2[s[left]] < mp1[s[left]]) {
                    formed--;
                }
                left++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(start, minLen);
    }
};