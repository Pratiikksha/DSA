class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx= max_element(nums.begin(),nums.end())-nums.begin();
        int mn= min_element(nums.begin(), nums.end()) - nums.begin();
        int ans=nums.size();
        int op1=max(mx,mn)+1;
        int op2=ans-min(mx,mn);
        int op3=min(mx,mn)+1+ans-max(mx,mn);
        return min({op1,op2,op3});
    }
};