class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>& coloured){
        coloured[node]=col;
        for(int adj:graph[node]){
            if(coloured[adj]==-1){
                if(!dfs(adj,!col,graph,coloured)) return false;
            }
            else if(coloured[adj]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>coloured(n,-1);
        for(int i=0;i<n;i++){
            if(coloured[i]==-1){
                if(!dfs(i,0,graph,coloured)) return false;
            }
        }
        return true;;
    }
};