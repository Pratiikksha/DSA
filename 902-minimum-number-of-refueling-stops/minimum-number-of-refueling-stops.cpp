class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int currFuel=startFuel;
        int i=0;
        int n=stations.size();
        int cnt=0;
        while(currFuel<target){
            while(i<n && currFuel>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            currFuel+=pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;

    }
};