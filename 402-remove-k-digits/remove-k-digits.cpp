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
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        if (i == ans.size())
            return "0";
        return ans.substr(i);
    }
};