class Solution {
public:
    int smallestNumber(int n, int t) {
        int i=n;
        while(1){
            int k=i;
            int p=1;
            while(k){
                p=p*(k%10);
                k=k/10;
            }
            if(p%t==0) return i;
            i++;
        }
        return -1;
    }
};