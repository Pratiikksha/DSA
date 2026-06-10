class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==1){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=0;
            }
            i++;
        }
        return max(maxi,cnt);
    }
};