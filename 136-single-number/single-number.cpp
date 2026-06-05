class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=0;
        for(int i:nums){
            k^=i;
        }
        return k;
    }
};