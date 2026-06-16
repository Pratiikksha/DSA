class Solution {
public:
    // string reverse(string s){
    //     string rev="";
    //     for(char c:s){
    //         rev=c+rev;
    //     }
    //     return rev;
    // }
    string processStr(string s) {
        string st="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='*'){
                if(!st.empty()) 
                st.pop_back();
            }
            else if(c=='#'){
                st=st+st;
            }
            else if(c=='%'){
                reverse(st.begin(),st.end());
            }
            else st=st+c;
        }
        return st;
    }
};