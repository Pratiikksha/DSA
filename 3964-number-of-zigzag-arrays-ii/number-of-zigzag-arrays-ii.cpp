class Solution {
public:
    static const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int N = 2 * m;

        Matrix T(N, vector<long long>(N, 0));

        for (int x = 0; x < m; x++) {

            // newUp[x] = sum(down[v]) for v < x
            for (int v = 0; v < x; v++) {
                T[x][m + v] = 1;
            }

            // newDown[x] = sum(up[v]) for v > x
            for (int v = x + 1; v < m; v++) {
                T[m + x][v] = 1;
            }
        }

        vector<long long> init(N, 0);

        // length = 2
        for (int x = 0; x < m; x++) {
            init[x] = x;           // up[x]
            init[m + x] = m - 1 - x; // down[x]
        }

        Matrix P = power(T, n - 2);

        long long ans = 0;

        for (int i = 0; i < N; i++) {
            long long cur = 0;

            for (int j = 0; j < N; j++) {
                cur = (cur + P[i][j] * init[j]) % MOD;
            }

            ans = (ans + cur) % MOD;
        }

        return (int)ans;
    }
};