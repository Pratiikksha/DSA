class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int n1 : nums1) {
            int i = 0;
            while (nums2[i] != n1) {
                i++;
                continue;
            }
            bool flag = false;
            for (; i < nums2.size(); i++) {
                if (nums2[i] > n1) {
                    flag = true;
                    ans.push_back(nums2[i]);
                    break;
                }
            }
            if (!flag) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};