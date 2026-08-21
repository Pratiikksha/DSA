class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(L, (long long)coins[i]);

                    // Prevent LCM from becoming unnecessarily huge
                    if (L > x / (coins[i] / g)) {
                        overflow = true;
                        break;
                    }

                    L = L / g * coins[i];
                }
            }

            if (overflow || L > x)
                continue;

            if (bits % 2 == 1)
                ans += x / L;
            else
                ans -= x / L;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        // Remove redundant coins
        sort(coins.begin(), coins.end());

        vector<int> useful;

        for (int c : coins) {
            bool redundant = false;

            for (int x : useful) {
                if (c % x == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant)
                useful.push_back(c);
        }

        coins = useful;

        long long low = coins[0];
        long long high = low * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};