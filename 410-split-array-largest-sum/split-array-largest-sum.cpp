class Solution {
public:
    bool canSplit(int x,vector<int>& nums, int k){
        int sum=0;
        int n=nums.size();
        int i=0;
        int count=0;
        while(i<n){
             if(sum+nums[i]<=x){
                sum+=nums[i];
                i++;
             }
             else{
                count++;
                sum=0;
             }
        }
        count++;
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int mini=*max_element(nums.begin(),nums.end());
        if(k==1){
            return sum;
        }
        int n=nums.size();
        if(k==n){
            return mini;
        }
        int h=sum;
        int l=mini;
        int mid=0;
        while(l<=h){
            mid=(l+h)/2;
            if(canSplit(mid,nums,k)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};