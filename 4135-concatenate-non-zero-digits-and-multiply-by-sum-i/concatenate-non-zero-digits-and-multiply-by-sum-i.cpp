class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        int k = n;
        long long d = 1;
        while (k > 0) {
            int r = k % 10;
            if (r != 0) {
                num = r * d + num;
                sum += r;
                d = d * 10;
            }
            k=k/10;
        }
        return (int)sum*num;
    }
};