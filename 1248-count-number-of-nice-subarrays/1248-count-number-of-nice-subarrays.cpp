class Solution {
public:
    int Odd(vector<int>& nums, int x) {
        int l = 0, odd = 0, count = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) {
                odd++;
            }
            while(odd > x) {
                if (nums[l] % 2 != 0) {
                    odd--;
                }
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return Odd(nums,k)-Odd(nums,(k-1));
    }
};