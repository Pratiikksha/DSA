class Solution {
public:

   void f(int open, int close,int n,string curr, vector<string>& ans){
    if(open==n && open==close){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        f(open+1,close,n,curr+'(',ans);
    }
    if(close<open){
        f(open,close+1,n,curr+')',ans);
    }
   }
    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string> ans;
        f(0,0,n,"",ans);
        return ans;
    }
};