class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,int>mp;
        for(char c:word){
            mp[c-'a']++;
        }
        vector<int>freq(26);
        int total=0;
        for(auto &p:mp){
            freq[p.first]=p.second;
            total+=p.second;
        }
        if(mp.size()<=8) return total;
        sort(freq.begin(),freq.end(),greater<>());
        for(int i=8;i<26;i++){
            if(i<16){
                total+=freq[i];
            }
            else if(i<24){
                total+=2*freq[i];
            }
            else total+=3*freq[i];
        }
        return total;
    }
};