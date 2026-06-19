class Solution {
public:
    int climbStairs(int n) {
        int ans=0;
        if(n==1) return 1;
        if(n==2) return 2;
        int k=3;
        int n1=1;
        int n2=2;
        while(k<=n){
            ans=n1+n2;
            n1=n2;
            n2=ans;
            k++;
        }
        return ans; 
    }
};