class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum=0;
        int total=0;
        for(int i=0;i<n/2;i++){
            sum+=piles[i];
            total+=piles[i];
        }
        int i=n/2;
        int j=n-1;
        int maxi=sum;
        while(i>=0 && j<n/2){
            sum=sum-piles[i]+piles[j];
            maxi=max(maxi,sum);
            total+=piles[j];
            i--;
            j--;
        }
        if(maxi>total/2) return true;
        return false;
    }
};