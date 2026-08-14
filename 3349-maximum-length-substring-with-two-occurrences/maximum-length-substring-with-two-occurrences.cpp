class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen=0;
        unordered_map<char,int>mp;
        int r=0;
        int l=0;
        int n=s.size();
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>2 && l<r){
                mp[s[l]]--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};