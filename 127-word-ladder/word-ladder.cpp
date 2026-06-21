class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int s=beginWord.size();
        int cnt=0;
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<s;i++){
                int original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};