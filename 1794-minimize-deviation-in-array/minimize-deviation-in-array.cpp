class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mini=INT_MAX;
        for(int i:nums){
            if(i%2) i=i*2;
            pq.push(i);
            mini=min(mini,i);
        }
        int ans=pq.top()-mini;
        while(true){
            int maxi=pq.top();
            pq.pop();
            if(maxi%2) break;
            maxi=maxi/2;
            pq.push(maxi);
            mini=min(mini,maxi);
            ans=min(ans,pq.top()-mini);
        }
        return ans;
    }
};