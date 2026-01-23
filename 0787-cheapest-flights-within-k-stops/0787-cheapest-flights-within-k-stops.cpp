class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>,
                       greater<pair<int,pair<int, int>>>>
            pq;
        pq.push({0,{src,0}});
        vector<vector<int>> dis(n, vector(k+2,INT_MAX));
        dis[src][0] = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            int a=t.first;
            int b=t.second.first;
            int stops=t.second.second;
            pq.pop();
            if(stops>k) continue;
            for (auto adjNode : adj[b]) {
                int newdist = a + adjNode.second;
                if (newdist < dis[adjNode.first][stops+1]) {
                    dis[adjNode.first][stops+1] = newdist;
                    pq.push({newdist,{adjNode.first,stops+1}});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<k+2;i++){
            ans=min(ans,dis[dst][i]);
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};