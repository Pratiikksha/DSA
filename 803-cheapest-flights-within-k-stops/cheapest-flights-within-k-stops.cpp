class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
          adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,src});
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        dis[src][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it[2]==dst) return it[0];
            if(it[1]>k) continue;
            int stops=it[1]+1;
            for(auto nei:adj[it[2]]){
                int newCost=it[0]+nei.second;
                if(dis[nei.first][stops]>newCost){
                    dis[nei.first][stops]=newCost;
                    pq.push({newCost,stops,nei.first});
                }
            }
        }
        return -1;
    }
};