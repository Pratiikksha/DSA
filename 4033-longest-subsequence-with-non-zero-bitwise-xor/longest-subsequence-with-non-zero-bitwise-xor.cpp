class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xorAll=0;
        int zeros=0;
        for(int i:nums){
            xorAll ^= i;
            if(i==0) zeros++;
        }
        if(xorAll!=0) return n;
        if(zeros==n) return 0;
        return n-1;
    }
};