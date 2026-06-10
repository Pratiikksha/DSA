class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=-1,k=n-1;
        int j=0;
        while(j<=k){
           if(nums[j]==0){
            i++;
            swap(nums[j],nums[i]);
            j++;
           }
           else if(nums[j]==1)j++;
           else{
            swap(nums[j],nums[k]);
            k--;
           }
        }
        return;
    }
};