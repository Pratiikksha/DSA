class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == mp[c]) {
                    st.pop();
                } else
                    return false;
            }
        }
        if (st.empty()) {
            return true;
        } else
            return false;
    }
};