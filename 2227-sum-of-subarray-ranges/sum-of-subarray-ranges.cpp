class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>st;
        vector<int>nse(n,n);
        vector<int>nge(n,n);
        vector<int>pse(n,-1);
        vector<int>pge(n,-1);
        long long maxTotal=0;
        long long minTotal=0;
        //PSE
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        //PGE
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        //NSE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        //NGE
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            long long count1=1LL*(i-pse[i])*(nse[i]-i);
            long long count2=1LL*(i-pge[i])*(nge[i]-i);
            minTotal+=nums[i]*count1;
            maxTotal+=nums[i]*count2;
        }
        return maxTotal-minTotal;


    }
};