class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLen=1;
        int n=nums.size();
        int i=0;
        unordered_map<int,int>freq;
        int j=0;
        while(j<n){
            freq[nums[j]]++;
            while(freq[nums[j]]>k && i<=j){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            int len=j-i+1;
            maxLen=max(maxLen,len);
            j++;
        }
        return maxLen;
    }
};