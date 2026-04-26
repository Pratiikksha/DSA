class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int r=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
           r^=nums[i]^i;
       } 
       return r^n;
    }
};