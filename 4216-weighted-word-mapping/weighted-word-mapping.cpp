class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans="";
        for(int i=0;i<n;i++){
            string s=words[i];
            int  weight=0;
            for(int j=0;j<s.size();j++){
                weight+=weights[s[j]-'a'];
            }
            int fin=weight%26;
            ans+=(97+25-fin);
        }
        return ans;
    }
};