class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k)
            return "0";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char c = num[i];
            while (k && !st.empty() && (st.top() - '0') > (c - '0')) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k && !st.empty()) {
            st.pop();
            k--;
        }
        if (st.empty()) {
            return "0";
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans=="") return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};