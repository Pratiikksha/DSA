class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        int maxi=0;
        int n=processorTime.size();
        int j=4*n-1;
        for(int i=0;i<n;i++){
            int m=max({tasks[j],tasks[j-1],tasks[j-2],tasks[j-3]});
            int maxTime=processorTime[i]+m;
            maxi=max(maxi,maxTime);
            j=j-4;
        }
        return maxi;
    }
};