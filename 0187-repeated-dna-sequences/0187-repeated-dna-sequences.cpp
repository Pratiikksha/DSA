class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return {};
        unordered_map<string, int> mp;
        int n = s.size();
        string st = s.substr(0, 10);
        mp[st]++;
        for (int i = 10; i < n; i++) {
            string st2 = st.substr(1, 9);
            st2 += s[i];
            mp[st2]++;
            st=st2;
        }
        vector<string> ans;
        for (auto it : mp) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};