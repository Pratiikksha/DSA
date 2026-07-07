class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n <2)
            return nums;
        int cnt1 = 0, el1 = INT_MIN;
        int cnt2 = 0, el2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                el1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0 && el1 != nums[i]) {
                el2 = nums[i];
                cnt2 = 1;
            } else if (el1 == nums[i]) {
                cnt1++;
            } else if (el2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
         cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                cnt1++;
            }
            if (nums[i] == el2) {
                cnt2++;
            }
        }

        int mini = n / 3 + 1;

        vector<int> result;

        if (cnt1 >= mini) {
            result.push_back(el1);
        }

        if (cnt2 >= mini && el1 != el2) {
            result.push_back(el2);
        }

        sort(result.begin(), result.end());

        return result;
    }
};