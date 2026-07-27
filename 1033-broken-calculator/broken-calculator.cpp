class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int s=startValue;
        int t=target;
        if(s>=t) return s-t;
        int cnt=0;
        while(t>s){
            if(t%2){
                t++;
                cnt++;
            }
            else{
                t=t/2;
                cnt++;
            }
        }
        cnt+=(s-t);
        return cnt;
    }
};