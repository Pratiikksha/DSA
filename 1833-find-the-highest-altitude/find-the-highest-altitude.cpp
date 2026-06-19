class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=max(0,gain[0]);
        int curr=gain[0];
        int n=gain.size();
        for(int i=1;i<n;i++){
            curr=curr+gain[i];
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};