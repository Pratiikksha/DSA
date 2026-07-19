class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int total = mp.size();
        int n = s.size();
        vector<int> vis(26, 0);
        stack<char> st;
        for (int i = 0; i < n; i++) {

            mp[s[i]]--;

            if (vis[s[i] - 'a'])
                continue;

            while (!st.empty() && st.top() > s[i] && mp[st.top()] > 0) {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};