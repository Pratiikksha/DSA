class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
        int i =1;
        vector<vector<int>> ans;
        int cnt=0;
        vector<int> temp = intervals[0];
        while(i < intervals.size()){
            if( intervals[i][0] < temp[1]){
                temp[0]= min(temp[0], intervals[i][0]);
                temp[1]= min(temp[1], intervals[i][1]);
                cnt++;
            }else{
                ans.push_back({temp[0], temp[1]});
                temp = intervals[i];
            }
            i++;
        }
        ans.push_back(temp);
        return cnt;
    }
};