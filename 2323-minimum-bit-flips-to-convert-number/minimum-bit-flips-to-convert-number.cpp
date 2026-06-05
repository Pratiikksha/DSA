class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal) return 0;
        int c=0;
        int k=start^goal;
        int n=32;
        while(n--){
            if(k&1) c++;
            k=k>>1;
        }
        return c;
    }
};