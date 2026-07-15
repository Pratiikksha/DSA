class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        for(int i=1;i<=2*n;i++){
            if(i%2)
            sumOdd+=i;
            else 
            sumEven+=i;
        }
        int a=max(sumOdd,sumEven);
        int b=min(sumOdd,sumEven);
        for(int i=b;i>=1;i--){
            if(a%i==0 && b%i==0) return i;
        }
        return 1;
    }
};