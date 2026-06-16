class Solution {
public:
    string reverse(string s){
        string rev="";
        for(char c:s){
            rev=c+rev;
        }
        return rev;
    }
    string processStr(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='*'){
                st=st.substr(0,st.size()-1);
            }
            else if(c=='#'){
                st=st+st;
            }
            else if(c=='%'){
                st=reverse(st);
            }
            else st=st+c;
        }
        return st;
    }
};