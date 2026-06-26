class Solution {
public:
    class BIT {
    public:
        int n;
        vector<int> bit;

        BIT(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        BIT ft(2 * n + 5);

        int prefix = 0;
        long long ans = 0;

        // Insert prefix sum = 0
        ft.update(n + 2, 1);

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            int idx = prefix + n + 2;

            // Count previous prefix sums < current prefix sum
            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return ans;
    }
};