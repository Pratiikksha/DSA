class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // land->water
        int landf=0;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            landf=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                int waterStart=max(landf,waterStartTime[j]);
                int totalFin=waterStart+waterDuration[j];
                mini=min(mini,totalFin);
            }
        }
        // water->land
         for(int i=0;i<m;i++){
            landf=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                int landStart=max(landf,landStartTime[j]);
                int totalFin=landStart+landDuration[j];
                mini=min(mini,totalFin);
            }
        }
        return mini;
    }
};