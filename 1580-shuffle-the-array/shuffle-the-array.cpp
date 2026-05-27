class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int x=0, y=0;
         int idx=0;
        for(int i=0;i<n;i++){
            x=nums[i]%10000;
            y=nums[i+n]%10000;
            nums[idx++]+=x*10000;
            nums[idx++]+=y*10000;
        }
        for(int i=0;i<2*n;i++){
            nums[i]/=10000;
        }
        return nums;
    }
};