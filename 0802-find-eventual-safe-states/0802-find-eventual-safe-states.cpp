class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& path, vector<int>& check) {
        vis[node] = 1;
        path[node] = 1;
        for (auto adjNode : graph[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                path[adjNode] = 1;
                if (dfs(adjNode, graph, vis, path, check)) {
                    return true;
                }
            } else if (path[adjNode]) {
                return true;
            }
        }
        path[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<int> ans;
        // for(int i=0;i<graph.size();i++){
        //     if(graph[i].szie()==0){
        //         ans.push_back(i);
        //     }
        // }
        int n = graph.size();
        vector<int> vis(n, 0), path(n, 0), check(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, path, check);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};