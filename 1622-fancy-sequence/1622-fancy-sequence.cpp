const int MOD = 1e9 + 7;

class Fancy {
public:
    vector<long long> sequence;
    long long globalAdd = 0;
    long long globalMul = 1;

    Fancy() {
        sequence.clear();
    }

    long long modPower(long long base, long long exponent) {
        if (exponent == 0)
            return 1;

        long long half = modPower(base, exponent / 2);
        long long result = (half * half) % MOD;

        if (exponent % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    void append(int val) {
        long long normalizedValue = (val - globalAdd + MOD) % MOD;
        normalizedValue = (normalizedValue * modPower(globalMul, MOD - 2)) % MOD;
        sequence.push_back(normalizedValue);
    }

    void addAll(int inc) {
        globalAdd = (globalAdd + inc) % MOD;
    }

    void multAll(int m) {
        globalMul = (globalMul * m) % MOD;
        globalAdd = (globalAdd * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= sequence.size())
            return -1;

        long long value = sequence[idx];
        value = (value * globalMul) % MOD;
        value = (value + globalAdd) % MOD;

        return value;
    }
};