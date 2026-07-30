class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int m=values.size();
        int n=values[0].size();
        vector<vector<int>>val(m,vector<int>(n,0));
        val=values;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>min_pq;
        for(int i=0;i<m;i++){
            min_pq.push({val[i].back(),i});
            val[i].pop_back();
        }
        int day=1;
        long long ans=0LL;
        while(!min_pq.empty()){
            long long  mini=(long long)min_pq.top().first;
            long long shop=(long long) min_pq.top().second;
            min_pq.pop();
            ans+=(long long)(day*mini);
            day++;
            if(val[shop].size()){
                min_pq.push({val[shop].back(),shop});
                val[shop].pop_back();
            }
        }
        return ans;
    }
};