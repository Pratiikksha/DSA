class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffixProduct(n,1);
        for(int i=n-2;i>=0;i--){
            suffixProduct[i]=suffixProduct[i+1]*nums[i+1];
        }
        int curr=nums[0];
        for(int i=1;i<n;i++){
            suffixProduct[i]=curr*suffixProduct[i];
            curr*=nums[i];
        }
        return suffixProduct;
    }
};