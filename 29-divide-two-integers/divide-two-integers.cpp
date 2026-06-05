class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend==INT_MIN && divisor ==-1){
            return INT_MAX;
       } 
        long long ans=0;
       long long dvd=labs(dividend);
       long long dvs=labs(divisor);
       while(dvd>=dvs){
        int shift=0;
        while(dvd>=(dvs<<(shift+1))){
            shift++;
        }
        ans+=(1LL<<shift);
        dvd-=(dvs<<shift);
       }
       if(divisor<0 ^ dividend<0){
        ans=-ans;
       }
       return (int)ans;
     }
};