class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k) return 0;
        vector<int>adjSum(n-1);
        for(int i=0;i<n-1;i++){
           adjSum[i]=weights[i]+weights[i+1]; 
        }
        sort(adjSum.begin(),adjSum.end());
        long long mini=weights[0]+weights[n-1];
        long long maxi=weights[0]+weights[n-1];
        for(int i=0;i<k-1;i++){
            mini+=adjSum[i];
        }
        for(int i=n-2;i>n-1-k;i--){
            maxi+=adjSum[i];
        }
        return maxi-mini;
    }
};