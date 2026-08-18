class Solution {
public:
    pair<int,int> expandAround(string& s, int l, int r){
        int n=s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
        }
        return {l+1,r-1};
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=1;
        int start=0;
        for(int i=0;i<n;i++){

            auto [l1,r1]=expandAround(s,i,i);
            int len=r1-l1+1;
            if(maxi<len){
                maxi=len;
                start=l1;
            }
            auto [l2,r2]=expandAround(s,i,i+1);
            len=r2-l2+1;
            if(maxi<len){
                maxi=len;
                start=l2;
            }
        }
        return s.substr(start,maxi);
    }
};