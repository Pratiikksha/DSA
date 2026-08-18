class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int start=0;
         int maxi=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                if(maxi<2){
                        maxi=2;
                        start=i;
                    }
            }
        }
        for(int i=3;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                if(s[j]==s[j+i-1] && dp[j+1][j+i-2]){
                    dp[j][j+i-1]=true;
                    if(maxi<i){
                        maxi=i;
                        start=j;
                    }
                }
            }
        }
        return s.substr(start,maxi);
    }
};