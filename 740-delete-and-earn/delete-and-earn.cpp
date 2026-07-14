class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>mp(20000,0);
        for(int i=0;i<n;i++){
            mp[nums[i]]+=nums[i];
        }
        int maxi=0;
        int x=mp[0];
        int y=max(mp[0],mp[1]);
        for(int i=2;i<20000;i++){
            maxi=max(x+mp[i],y);
            x=y;
            y=maxi;
        }
        return maxi;
    }
};