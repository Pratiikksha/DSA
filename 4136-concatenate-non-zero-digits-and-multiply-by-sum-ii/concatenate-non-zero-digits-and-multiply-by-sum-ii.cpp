class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<long long> A(n + 1, 0);      // digit sum
        vector<long long> B(n + 1, 0);      // concatenated non-zero number
        vector<int> ln(n + 1, 0);           // count of non-zero digits

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {

            int d = s[i] - '0';

            A[i + 1] = A[i] + d;

            if (d == 0)
                B[i + 1] = B[i];
            else
                B[i + 1] = (B[i] * 10 + d) % MOD;

            ln[i + 1] = ln[i] + (d != 0);
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1] + 1;

            long long sub =
                (B[l] * pow10[ln[r] - ln[l]]) % MOD;

            long long x = (B[r] - sub + MOD) % MOD;

            long long sum = A[r] - A[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};