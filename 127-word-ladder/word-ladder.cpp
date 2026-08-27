class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.contains(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        unordered_map<string, int> vis;
        while (!q.empty()) {
            cnt++;
            int size = q.size();
            while (size--) {
                string s = q.front();
                if(s==endWord) return cnt;
                q.pop();
                for (int i = 0; i < s.size(); i++) {
                    string changed=s;
                    for (char c = 'a'; c <= 'z'; c++) {
                        changed[i]=c;
                        if(st.contains(changed) && vis.find(changed)==vis.end()){
                            vis[changed]=1;
                            q.push(changed);
                        }
                    }
                    changed=s;
                }
            }
        }
        return 0;
    }
};