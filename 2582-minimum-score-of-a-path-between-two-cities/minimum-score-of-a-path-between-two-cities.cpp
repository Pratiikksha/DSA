class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=INT_MAX;
        pq.push({1e7,1});
        vector<int>scores(n+1,INT_MAX);
        while(!pq.empty()){
            int score=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n){
                ans=min(ans,score);
            }
            for(auto it:adj[node]){
                int nScore=min(score,it.second);
                if(nScore<scores[it.first]){
                pq.push({nScore,it.first});
                scores[it.first]=nScore;
                }
            }
        }
        return ans;
    }
};