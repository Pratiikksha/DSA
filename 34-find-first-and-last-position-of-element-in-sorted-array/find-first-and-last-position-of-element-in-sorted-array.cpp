class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        // First occurrence
        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        int first = low;

        // Target doesn't exist
        if(n == 0 || nums[first] != target)
            return {-1, -1};

        // Last occurrence
        low = 0;
        high = n;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }

        int last = low - 1;

        return {first, last};
    }
};