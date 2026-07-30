class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> lastSeen; // prime -> last index it appears at

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    lastSeen[p] = i;
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) lastSeen[x] = i; // remaining prime factor
        }

        int reach = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    reach = max(reach, lastSeen[p]);
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) reach = max(reach, lastSeen[x]);

            if (reach == i) {
                if (i == n - 1) return -1; // whole array is one connected block
                return i;
            }
        }
        return -1;
    }
};