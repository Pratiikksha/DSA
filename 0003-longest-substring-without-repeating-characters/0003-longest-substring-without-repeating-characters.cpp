class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1) return n;
        int right=1;
        int left=0;
        int maxLen=1;
        unordered_map<char,int> mp;
        mp[s[0]]=0;
        while(left<right && right<n){
            if(mp.count(s[right])){
                left=max(left,mp[s[right]]+1);
            }
            int len=right-left+1;
            maxLen=max(maxLen,len);
            mp[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};