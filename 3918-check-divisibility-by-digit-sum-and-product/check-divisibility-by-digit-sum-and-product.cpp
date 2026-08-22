class Solution {
public:
    bool checkDivisibility(int n) {
     int k=n;
     int p=1, s=0;
     while(k){
        int d=k%10;
        s+=d;
        p*=d;
        k=k/10;
     }   
     s+=p;
     if(n%s) return false;
     return true;
    }
};