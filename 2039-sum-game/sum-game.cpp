class Solution {
public:
    bool sumGame(string num) {
        int leftSum=0;
        int lq=0;
        int rightSum=0;
        int rq=0;
        int n=num.size();
        for(int i=0;i<n/2;i++){
            if(num[i]=='?') {
                lq++;
            }
            else {
                leftSum+=(num[i]-'0');
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                rq++;
            }
            else {
                rightSum+=(num[i]-'0');
            }
        }
        if((lq+rq)%2) return true;
         return leftSum - rightSum != 9 * (rq - lq) / 2;
    }
};