class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto edge:richer){
            adj[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i:adj[node]){
                degree[i]--;
                if(degree[i]==0){
                    q.push(i);
                }
                if(quiet[ans[i]]>quiet[ans[node]]){
                    ans[i]=ans[node];
                }
            }
        }
        return ans;
    }
};