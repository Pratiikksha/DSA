class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
      sort(events.begin(),events.end());
      int n=events.size();
      vector<int>start(n);
      for(int i=0;i<n;i++){
        start[i]=events[i][0];
      }
      vector<int>nextIndex(n);  
      for(int i=0;i<n;i++){
       int end=events[i][1];
       int l=upper_bound(start.begin(),start.end(),end)-start.begin();
       nextIndex[i]=l;
      }
      vector<vector<int>> dp(n+1,vector<int>(k+1,0));
      for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                int skip = dp[i + 1][j];
                int take = events[i][2] + dp[nextIndex[i]][j - 1];
                
                dp[i][j] = max(skip, take);
            }
        }
        
        return dp[0][k];
    }
};