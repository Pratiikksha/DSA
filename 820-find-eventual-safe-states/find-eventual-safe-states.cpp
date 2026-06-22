class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>outDegree(n,0);
        for(int i=0;i<n;i++){
            outDegree[i]=graph[i].size();
            for(int u:graph[i]){
                adj[u].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outDegree[i]==0){
                q.push(i);
            }
        }
        if(q.empty()) return {};
        vector<int>vis(n,0);
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int nei:adj[node]){
                if(!vis[nei]){
                    outDegree[nei]--;
                    if(outDegree[nei]==0) q.push(nei);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};