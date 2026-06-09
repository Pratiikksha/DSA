class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char,int> mp;
        for(auto c:t){
            mp[c]++;
        }
        unordered_map<char,int>curr;
        int req=mp.size();
        int formed=0;
        int r=0;
        int l=0;
        int start=0;
        int minLen=INT_MAX;
        while(r<=s.size()){
            char c=s[r];
            curr[c]++;
            if(mp.count(c)&&curr[c]==mp[c]){
                formed++;
            }
            while(l<=r && formed==req){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                curr[s[l]]--;
                if(mp.count(s[l])&& curr[s[l]]<mp[s[l]]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};