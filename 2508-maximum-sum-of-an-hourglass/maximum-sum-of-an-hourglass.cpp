class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                int sum=0;
                for(int k=j;k<j+3;k++){
                    sum+=grid[i][k];
                    sum+=grid[i+2][k];
                }
                sum+=grid[i+1][j+1];
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};