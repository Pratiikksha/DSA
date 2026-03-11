class Solution {
public:
    int bitwiseComplement(int num) {
        int mask = 0;
        int temp = num;
        if(num==0) return 1;
        while(temp){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return mask ^ num;
    }
};