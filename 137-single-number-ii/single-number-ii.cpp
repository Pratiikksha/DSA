class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            int diff=1<<i;
            for(int j:nums){
                if(diff &  j){
                    cnt++;
                }
            }
            if(cnt%3){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};