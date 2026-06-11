class Solution {
public:
    bool isValid(int x, vector<int>& nums, int threshold) {
        long long  sum = 0;
        for (int i : nums) {
            sum += (long long)((i + x - 1) / x);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        long long h = (*max_element(nums.begin(), nums.end()))*1LL;
        long long l = 1;

        while (l <= h) {
            long long mid = (l + h) / 2;
            if (isValid(mid, nums, threshold)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};