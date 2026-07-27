class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        if(n==1){
            if(edges.size()){
                return -1;
            }
            return 1;
        }
        vector<vector<int>>dp(n, vector<int>(26,0));
        vector<vector<int>>adj(n);
        vector<int>inDegree(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            inDegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!inDegree[i]){
                q.push(i);
                dp[i][colors[i]-'a']=1;
             }
        }
        if(q.empty()) return -1;
        int maxi=1;
        int processed=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            processed++;
            for(auto i:adj[node]){
                dp[i][colors[i]-'a']=max(dp[i][colors[i]-'a'],dp[node][colors[i]-'a']+1);
                for(int c=0;c<26;c++){
                dp[i][c]=max(dp[node][c],dp[i][c]);
                maxi=max(maxi,dp[i][c]);
                }
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(processed!=n) return -1;
        return maxi;
    }
};