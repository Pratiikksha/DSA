class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(int i:nums){
            x^=i;
        }
       unsigned int diff = (unsigned int)x & -(unsigned int)x;
        int g1=0;
        int g2=0;
        for(int i:nums){
            if(i&diff){
                g1^=i;
            }
            else {
                g2^=i;
            }
        }
        return {g1,g2};
    }
};