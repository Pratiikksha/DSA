class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
        int l=0;
        int r=n-1;
        while(l<n){
            int left=prefix[l];
            int right=prefix[n]-prefix[l+1];
            if(left==right) return l;
            l++;
        }
        return -1;
    }
};