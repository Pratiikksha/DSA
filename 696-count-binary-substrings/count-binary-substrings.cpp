class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int curr=1;
        int c1=s[0];
        int ans=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            char c=s[i];
            if(c1==c){
                curr++;
            }
            else {
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
                c1=c;
            }
        }
        ans += min(prev, curr);
        return ans;
    }
};