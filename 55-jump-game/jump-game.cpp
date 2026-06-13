class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        if (nums[0] == 0)
            return false;
        int maxReach = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i > maxReach)
                return false;
            if (nums[i] != 0)
                maxReach = max(maxReach, i + nums[i]);
        }
        if (maxReach >= n - 1)
            return true;
        else
            return false;
    }
};