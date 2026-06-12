class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int k=s.size();
        if(k==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int n=g.size();
        if(n==0) return 0;
        if(g[0]>s[k-1]) return 0;
        for(int i=n-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                if(g[i]<=s[j]){
                    cnt++;
                    s[j]=0;
                    break;
                }
            }
        }
        return cnt;
    }
};