class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        if(adj[k].size()==0) return -1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        time[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int node=it.second;
            for(auto nei:adj[node]){
                int newTime=t+nei.second;
                if(time[nei.first]>newTime){
                    time[nei.first]=newTime;
                    pq.push({newTime,nei.first});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i:time){
            if(i==INT_MAX) return -1;
            maxi=max(maxi,i);
        }
        return maxi;
    }
};