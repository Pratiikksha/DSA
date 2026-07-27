class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=0;
        int m2=0;
        for(int i:nums){
            if(m1<i){
                m2=m1;
                m1=i;
            }
            else{
                m2=max(m2,i);
            }
        }
        return (m1-1)*(m2-1);
    }
};