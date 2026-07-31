class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char c:tasks){
            mp[c]++;
        }
        int total=tasks.size();
        priority_queue<pair<int,char>>pq;
        queue<pair<int,pair<int,char>>>cooldown;
        int interval=0;
        for(auto &p:mp){
            pq.push({p.second,p.first});
        }
        while(!pq.empty()){
            while(!cooldown.empty() && cooldown.front().first<=interval){
                auto it=cooldown.front();
                cooldown.pop();
                pq.push({it.second.first,it.second.second});
            }
            auto curr=pq.top();
            pq.pop();
            char c=curr.second;
            if(curr.first-1){
            cooldown.push({interval+n+1,{curr.first-1,c}});
            }
            interval++;
            if(pq.empty() && !cooldown.empty()){
                auto it=cooldown.front();
                cooldown.pop();
                pq.push({it.second.first,it.second.second});
                interval=it.first;
            }
        }
        return interval;
    }
};