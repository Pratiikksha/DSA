class Solution {
public:
    void solve(int idx,string& s,vector<string>&curr,vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int a,int b){
        while(a<=b){
            if(s[a++]!=s[b--])
            return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,s,curr,ans);
        return ans;
    }
};