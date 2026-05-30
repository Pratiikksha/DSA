class Solution {
public:
    const long long mod = 1e9 + 7;
    long long power(long long a, long long b){
        long long res=1;
        while(b){
            if(b&1){
                res=(res*a) %mod;
            }
            a=(a*a) %mod;
            b=b>>1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long prime=n/2;
        return (power(5,even)*power(4,prime))%mod;
    }
};