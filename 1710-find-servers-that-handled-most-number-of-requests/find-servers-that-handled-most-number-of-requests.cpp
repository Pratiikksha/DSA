class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>busy;
        set<int>free;
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        vector<int>count(k,0);
        for(int i=0;i<arrival.size();i++){
            while(!busy.empty() && arrival[i]>=busy.top().first){
                free.insert(busy.top().second);
                busy.pop();
            }
            if(free.empty()) continue;
            int s=i%k;
            auto it=free.lower_bound(s);
            if(it==free.end()){
                it=free.begin();
            }
            int server=*it;
            free.erase(it);
            busy.push({arrival[i]+load[i],server});
            count[server]++;
        }
        int maxi=*max_element(count.begin(),count.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(count[i]==maxi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};