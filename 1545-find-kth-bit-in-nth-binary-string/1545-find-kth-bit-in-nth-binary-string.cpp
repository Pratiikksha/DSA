class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1)
            return '0';
        int mid = pow(2, n - 1);
        if (k == mid)
            return '1';
        else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            char c = findKthBit(n - 1, pow(2, n) - k);
            if (c== '0')
                return '1';
            else
                return '0';
        }
    }
};