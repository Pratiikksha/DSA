class Solution {
public:
    bool dfs(int x,vector<vector<int>>& adj, vector<int>& coloured){
        for(int i:adj[x]){
            if(coloured[i]==-1){
                coloured[i]=!coloured[x];
                if(!dfs(i,adj,coloured))
                return false;
            }
            else if(coloured[i]==coloured[x]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(auto i:dislikes){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int>coloured(n,-1);
        for(int i=0;i<n;i++){
            if(coloured[i]==-1){
                if(!dfs(i,adj,coloured)){
                    return false;
                }
            }
        }
        return true;
    }
};