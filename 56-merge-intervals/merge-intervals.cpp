class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if(n==1) return intervals;
        int i=0;
        int j=1;
        vector<vector<int>>ans;
        while(i<n && j<n){
            int newi=intervals[i][0];
            int newy=intervals[i][1];
            while(j<n && intervals[j][0]>=intervals[i][0] && intervals[j][0]<=newy){
                newy=max(newy,intervals[j][1]);
                j=j+1;
            }
            ans.push_back({newi,newy});
            i=j;
        }
        return ans;
    }
};