class Solution {
public:
    bool isValid(int mid, long long k,vector<vector<pair<int,int>>>& adj,vector<bool>&online,vector<int>&topoSort) {
        int n=online.size();
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
       for(auto edge:topoSort){
        if(dis[edge]==LLONG_MAX) continue;
        for(auto it:adj[edge]){
            if(it.second<mid || !online[it.first]) continue;
            dis[it.first]=min(dis[it.first],dis[edge]+it.second);
        }
       }
       return dis[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int maxi = 0;
        vector<int> indegree(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            maxi = max(maxi, wt);
            indegree[v]++;
            adj[u].push_back({v, wt});
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topoSort;
        while (!q.empty()) {
            int node = q.front();
            topoSort.push_back(node);
            q.pop();
            for (auto i : adj[node]) {
                indegree[i.first]--;
                if (indegree[i.first] == 0) {
                    q.push(i.first);
                }
            }
        }
        int high = maxi;
        int low = 0;
        int ans=-1;
        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (isValid(mid, k, adj,online,topoSort)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid-1;
        }
        return ans;
    }
};