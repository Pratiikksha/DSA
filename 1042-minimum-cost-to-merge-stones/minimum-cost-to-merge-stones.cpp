class Solution {
public:
    const int INF = 1e9;
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int left = n;
        while (left >= k) {
            left = left - k + 1;
        }
        if (left > 1)
            return -1;
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(k+1, INF)));
        for (int i = 0; i < n; i++) {
            prefix[i+1]=stones[i]+prefix[i];
            dp[i][i][1] = 0;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                for(int p=2;p<=k;p++){
                    for(int mid=i;mid<j;mid++){
                        if(dp[i][mid][1]==INF || dp[mid+1][j][p-1]==INF) continue;
                        dp[i][j][p]=min(dp[i][j][p],dp[i][mid][1]+dp[mid+1][j][p-1]);
                    }
                }
                if(dp[i][j][k]!=INF){
                    int sum=prefix[j+1]-prefix[i];
                    dp[i][j][1]=min(dp[i][j][1],dp[i][j][k]+sum);
                }
            }
        }
        return dp[0][n-1][1];
    }
};