class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        if(n<=999) return 0;
        if(n<999999){
            ans+=n-1000+1;
        }
        return ans;
    }
};