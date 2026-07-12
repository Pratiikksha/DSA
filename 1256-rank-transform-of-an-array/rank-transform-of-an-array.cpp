class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if(mp.count(arr[i])==0){
            mp[arr[i]]=i;}
        }
        int i=1;
        for(auto &[a,b]:mp){
            mp[a]=i;
            i++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};