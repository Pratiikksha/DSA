class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int>mx;
        deque<int>mn;
        int r=0,l=0;
        int maxLen=1;
        while(r<n){
            while(!mx.empty() && nums[mx.back()]<=nums[r]){
                mx.pop_back();
            }
            while(!mn.empty() && nums[mn.back()]>=nums[r]){
                mn.pop_back();
            }
            mx.push_back(r);
            mn.push_back(r);
            while(nums[mx.front()]-nums[mn.front()]>limit && l<r){
                l++;
                while(!mx.empty() && mx.front()<l){
                    mx.pop_front();
                }
                while(!mn.empty() && mn.front()<l){
                    mn.pop_front();
                }
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};