class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int ans=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            ans=accumulate(accounts[i].begin(),accounts[i].end(),0);
            if(maxi<ans){
                maxi=ans;
            }
        }
        return maxi;
    }
};