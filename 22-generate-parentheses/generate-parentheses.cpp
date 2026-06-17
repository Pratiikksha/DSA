class Solution {
public:
    void generate(string curr,int open,int close,int n,vector<string>&ans){
        if(open>n || close>n) return;
        if(curr.size()==2*n && open==n && close==n){
          ans.push_back(curr);
          return;
        }
        curr.push_back('(');
        open++;
        generate(curr,open,close,n,ans);
        curr.pop_back();
        open--;
        if(curr.back()=='(' || open>close){
            curr.push_back(')');
            close++;
            generate(curr,open,close,n,ans);
        }
        curr.pop_back();
        close--;
        return;
    }
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        vector<string>ans;
        string s="(";
        generate(s,1,0,n,ans);
        return ans;
    }
};