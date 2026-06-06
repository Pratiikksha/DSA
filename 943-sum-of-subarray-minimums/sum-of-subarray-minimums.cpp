class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>> st;
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        stack<pair<int,int>>st2;
        for(int i=0;i<n;i++){
            while(!st2.empty()&& st2.top().first>arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                pse[i]=st2.top().second;
            }
            st2.push({arr[i],i});
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long count=1LL*(i-pse[i])*(nse[i]-i);
            ans=(ans+(count*arr[i]))%mod;
        }
        return (int)ans;
    }
};