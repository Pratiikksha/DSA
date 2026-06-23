class Solution {
public:
    int const mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>time(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        time[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long t=it.first;
            int node=it.second;
            if(t > time[node]) continue;
            for(auto nei:adj[node]){
                long long newTime=t+nei.second;
                if(time[nei.first]>newTime){
                    time[nei.first]=newTime;
                    ways[nei.first]=ways[node];
                    pq.push({newTime,nei.first});
                }
                else if(time[nei.first]==newTime){
                    ways[nei.first] =(ways[nei.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};