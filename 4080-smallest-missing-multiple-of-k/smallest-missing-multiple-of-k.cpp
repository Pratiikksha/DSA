class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]%k==0 && (nums[i]/k)<=n && (nums[i] / k) != i + 1 &&   nums[nums[i] / k - 1] != nums[i]){
                swap(nums[i], nums[nums[i]/k -1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%k==0 && nums[i]/k != i+1){
                 return k*(i+1);
            }
            else if(nums[i]%k){
                return k*(i+1);
            }
        }
        return k*(n+1);
    }
};