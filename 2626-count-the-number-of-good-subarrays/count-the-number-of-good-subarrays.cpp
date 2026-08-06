class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,int>mp;
        long long pairs=0;
        int l=0;
        for(int r=0;r<n;r++){
            pairs+=mp[nums[r]];
            mp[nums[r]]++;
            while(pairs>=k){
                ans+=(n-r);
                mp[nums[l]]--;
                pairs-=mp[nums[l]];
                l++;

            }
        }
        return ans;
    }
};