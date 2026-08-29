class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            ans[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - prices[ans[i]];
            }
        }
        return ans;
    }
};