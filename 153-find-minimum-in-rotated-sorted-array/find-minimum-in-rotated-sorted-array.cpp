class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mid=0;
        int mini=INT_MAX;
        while(l<=h){
            mid=(l+h)/2;
            mini=min(mini,nums[mid]);
            if(nums[mid]>nums[h]){
                l=mid+1;
            }
            // else if(nums[mid]==nums[h]){
            //     h=mid-1;
            // }
            else if(nums[mid]>nums[l]){
                h=mid-1;;
            }
            else{
                h=mid-1;
            }
        }
        return mini;
    }
};