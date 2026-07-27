class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxi=0;
        int sum=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]){
                sum+=customers[i];
            }
        }
        maxi=sum;
        int i=minutes;
        int j=0;
        while(i<n){
            if(grumpy[j]){
                sum=sum-customers[j];
            }
            if(grumpy[i])
            sum+=customers[i];
            maxi=max(maxi,sum);
            i++;
            j++;
        }
        int satisfy=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i])
            satisfy+=customers[i];
        }
        return satisfy+maxi;
    }
};