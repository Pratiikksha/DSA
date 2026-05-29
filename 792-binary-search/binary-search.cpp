class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h=nums.size()-1;
        int l=0;
        int mid=0;
        while(l<=h){
            mid=(h+l)/2;
            if(target==nums[mid]){
                return mid; 
            }
            else if(target<nums[mid]){
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return -1;
    }
};