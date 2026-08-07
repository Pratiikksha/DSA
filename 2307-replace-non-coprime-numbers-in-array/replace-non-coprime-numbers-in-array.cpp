class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int k=nums[i];
            if(!st.empty() && gcd(st.top(),k)>1){
            int l=lcm(k,st.top());
            st.pop();
            st.push(l);
            while(st.size()>=2){
            int up=st.top();
            st.pop();
            int down=st.top();
            st.pop();
            if(gcd(up,down)>1){
                st.push(lcm(up,down));
            }
            else {
                st.push(down);
                st.push(up);
                break;
            }}
           }
           else
            st.push(nums[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};