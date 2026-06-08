class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stack<int> st1;
        stack<int> st2;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                st1.push(nums[i]);
            }
            else if(nums[i]>pivot){
                st2.push(nums[i]);
            }
            else{
                cnt++;
            }
        }
        int i=n-1;
        while(!st2.empty()){
            nums[i]=st2.top();
            st2.pop();
            i--;
        }
        while(cnt>0 && i>=0){
            nums[i]=pivot;
            i--;
            cnt--;
        }
        while(!st1.empty() && i>=0){
            nums[i]=st1.top();
            st1.pop();
            i--;
        }
        return nums;
    }
};