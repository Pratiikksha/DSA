class Solution {
public:
    int lcs(string w1, string w2){
        int n1=w1.size();
        int n2=w2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(w1[i-1]==w2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
    int minInsertions(string s) {
        string st=s;
        reverse(st.begin(),st.end());
        int k=lcs(s,st);
        int l=s.size()-k;
        return l;
    }
};