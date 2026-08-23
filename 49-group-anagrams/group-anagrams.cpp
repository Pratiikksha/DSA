class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto [s,v]:mp){
            vector<string>temp;
            for(string st:v){
                temp.push_back(st);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};