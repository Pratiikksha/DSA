class Solution {
public:
    double power(double a,int b){
        if(b==0){
            return 1;
        }
        double half = power(a, b / 2);
        if(b%2==0){
            return half*half;

        }
        else{
         return a*half*half;
        }
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        long long k=n;
        if (k < 0) {
            x = 1 / x;
            k = -k;
        }
        return power(x,k);
    }
};