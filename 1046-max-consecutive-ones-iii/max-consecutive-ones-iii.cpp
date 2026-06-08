class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        int zeros = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if(nums[l]==0)
                zeros--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};