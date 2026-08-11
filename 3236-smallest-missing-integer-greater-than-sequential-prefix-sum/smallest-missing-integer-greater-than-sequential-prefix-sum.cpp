class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        int len=1;
        int sumLongest=nums[0];
        for(int i = 0; i < n-1; i++){
                if(nums[i]==nums[i+1]-1)
                    sumLongest+=nums[i+1];
                else
                break; 
        }
        unordered_set<int> st;
        for(int i:nums){
            st.insert(i);
   }
        for(int i=sumLongest;;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return 0;
    }
};