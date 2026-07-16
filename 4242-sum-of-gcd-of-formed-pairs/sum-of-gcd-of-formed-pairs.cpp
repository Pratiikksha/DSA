class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int>prefix(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefix[i]=gcd(mx,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        int i=0, j=n-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return sum;
    }
};