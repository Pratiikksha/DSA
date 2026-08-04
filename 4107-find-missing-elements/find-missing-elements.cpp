class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        if(nums.size()==maxi-mini+1) return {};
        vector<int>ans;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = mini; i <= maxi; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};