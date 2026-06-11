class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int h = n - 1;
        int mid = 0;
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        while (l <= h) {
            mid = (l + h) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            else if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    h = mid;
                } else {
                    l = mid;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2!=0){
                    h=mid+1;
                }
                else{
                    l=mid;
                }
            }
        }
        return nums[mid];
    }
    };