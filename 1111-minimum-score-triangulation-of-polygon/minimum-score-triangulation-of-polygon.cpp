class Solution {
public:
    int solve(int i, int j, vector<int>& values, vector<vector<int>>&dp) {
    if(dp[i][j]!=INT_MAX) return dp[i][j];
    if (j - i + 1 < 3)
        return dp[i][j]=0;

    if (j - i + 1 == 3)
        return dp[i][j]=values[i] * values[i+1] * values[j];

    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++) {

        int left = solve(i, k, values,dp);
        int right = solve(k, j, values,dp);

        int triangle = values[i] * values[k] * values[j];

        ans = min(ans, left + right + triangle);
    }

    return dp[i][j]=ans;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        solve(0,n-1,values,dp);
        return dp[0][n-1];
        
    }
};