class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int cur=0;
        while(i<n){
            if(nums[i]!=0){
                nums[cur++]=nums[i];
            }
            i++;
        }
        while(cur<n){
            nums[cur++]=0;
        }
        return;
    }
};