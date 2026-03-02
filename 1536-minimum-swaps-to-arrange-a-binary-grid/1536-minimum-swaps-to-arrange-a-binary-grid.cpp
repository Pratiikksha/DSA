class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        vector<int> endingWzeros(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (grid[j][i] == 1)
                    break;
                endingWzeros[j]++;
            }
        }
        int swaps=0;
        for(int i=0;i<n;i++){
             int need=n-i-1;
             int j=i;
             while(j<n && endingWzeros[j]<need)
             j++;
             if(j==n) return -1;
             while(j>i){
                swap(endingWzeros[j],endingWzeros[j-1]);
                swaps++;
                j--;
             }
        }
        return swaps;
    }
};