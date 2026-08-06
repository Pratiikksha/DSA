class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        int cnt=0;
        long long ans=0;
        unordered_map<int,long long>mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                cnt++;
            }
            cnt%=modulo;
            int need=(cnt-k+modulo)%modulo;
            ans+=mp[need];
            mp[cnt]++;
        }
        return ans;
    }
};