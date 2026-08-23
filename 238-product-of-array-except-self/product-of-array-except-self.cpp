class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffixProduct(n+1,1);
        for(int i=n-1;i>=0;i--){
            suffixProduct[i]=suffixProduct[i+1]*nums[i];
        }
        vector<int>ans(n,1);
        ans[0]=suffixProduct[1];
        int curr=nums[0];
        for(int i=1;i<n;i++){
            ans[i]=curr*suffixProduct[i+1];
            curr*=nums[i];
        }
        return ans;
    }
};