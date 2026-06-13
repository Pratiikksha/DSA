class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini=0;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<mini){
                mini=i;
            }
        }
        if(strs[mini]=="") return "";
        int n=strs[mini].size();
        string common="";
        for(int i=0;i<n;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=strs[mini][i]){
                    return common;
                }
            }
            common+=strs[mini][i];
        }
        return common;
    }
};