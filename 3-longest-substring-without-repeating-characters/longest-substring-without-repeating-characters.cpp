class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int maxi=1;
        unordered_map<char,int> mp;
        int l=0;
        int r=1;
        int n=s.size();
        mp[s[0]]=0;
        while(r<n && l<n){
            if(mp.count(s[r])&& mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
            maxi=max(maxi,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxi;
    }
};