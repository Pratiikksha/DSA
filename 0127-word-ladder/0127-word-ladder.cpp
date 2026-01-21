class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int n = beginWord.size();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [s, steps] = q.front();
            q.pop();
            if (s == endWord)
                return steps;
            for (int i = 0; i < n; i++) {
                char ch = s[i];
                for (int j = 0; j < 26; j++) {
                    s[i] = j + 'a';
                    if (st.count(s)) {
                        st.erase(s);
                        q.push({s, steps + 1});
                    }
                }
                s[i] = ch;
            }
        }
        return 0;
    }
};