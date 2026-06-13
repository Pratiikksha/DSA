class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b){
            return a.second>b.second;
        });
        for(auto it:v){
            int k=it.second;
            while(k){
            ans+=it.first;
            k--;}
        }
        return ans;
    }
};