class Solution {
public:
    bool dfs(int num, vector<vector<int>>& adj,
             vector<vector<int>>& prerequisites, vector<int>& vis,
             vector<int>& path) {
        vis[num] = 1;
        path[num] = 1;
        for (auto adjNode : adj[num]){
            if(!vis[adjNode]){
                if(dfs(adjNode,adj,prerequisites,vis,path))
                return true;
                path[adjNode]=0;
            }
            else if(vis[adjNode] && path[adjNode]){
                return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                bool k=dfs(i,adj,prerequisites,vis,path);
                if(k) return false;
                path[i]=0;
            }
        }
        return true;
    }
};