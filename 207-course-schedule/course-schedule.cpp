class Solution {
public:
    bool cycle(int V, vector<int>& pathVis, vector<int>& vis,
               vector<vector<int>>& adj) {
        vis[V] = 1;
        pathVis[V] = 1;
        for (int i : adj[V]) {
            if (vis[i] && pathVis[i]) {
                return false;
            } else if (!vis[i]) {
                if (!cycle(i, pathVis, vis, adj))
                    return false;
            }
        }
        pathVis[V] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        if(n==0) return true;
        for (int i = 0; i < n; i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!cycle(i, pathVis, vis, adj))
                    return false;
            }
        }
        return true;
        ;
    }
};