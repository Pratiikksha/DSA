class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        priority_queue<pair<int,int>>mx;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mn;
        int r=0;
        int l=0;
        int maxLen=1;
        while(r<n){
            mx.push({nums[r],r});
            mn.push({nums[r],r});
            while(mx.top().first-mn.top().first > limit){
                  l++;
                 while(!mx.empty() && mx.top().second<l){
                 mx.pop();
                 }
                while(!mn.empty() && mn.top().second<l){
                mn.pop();
                 }
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};