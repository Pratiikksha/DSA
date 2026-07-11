class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        long long sum=0;
        for(int i:machines){
            sum+=i;
        }
        if(sum%n!=0) return -1;
        int k=(int)(sum/n);
        int ans=0;
        int balance=0;
        for(int i=0;i<n;i++){
            int extra=machines[i]-k;
            balance+=extra;
            ans=max({ans,abs(balance),extra});
        }
        return ans;
    }
};