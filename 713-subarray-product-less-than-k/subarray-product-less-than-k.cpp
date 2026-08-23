class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k <= 1)
            return 0;
        int l=0;
        int r=0;
        int curr=1;
        int ans=0;
        while(r<n){
            curr*=nums[r];
            while(curr>=k){
                curr/=nums[l];
                l++;
            }
            int len=r-l+1;
            ans+=len;
            r++;
        }
        return ans;
    }
};