class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int count = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans=0;
        while (r < n) {
            if (nums[r] % 2 == 1) {
                count++;
            }
            while (count>k && l<=r){
                if(nums[l]%2){
                    count--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};