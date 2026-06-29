class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int k=s.size();
        if(k==0) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        if(g[0]>s[k-1]) return 0;
        int cnt=0;
        int i=n-1;
        int j=k-1;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                cnt++;
                i--;
                j--;
            }
            else {
                i--;
            }
        }
        return cnt;
    }
};