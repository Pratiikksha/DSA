class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        int ones = freq[1];
        freq.erase(1);
        int ans = 0;
        for (auto& [x, t] : freq) {
            long long cur = x;
            int len = 1;

            while (freq.count(cur) && freq[cur] >= 2 && freq.count(cur * cur)) {
                long long nxt = cur * cur;
                if (!freq.count(nxt))
                    break;

                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }
        if (ones <= ans)
            return ans;

        if (ones % 2 == 0)
            ones--;
        return ones;
    }
};