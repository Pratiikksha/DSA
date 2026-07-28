class Solution {
public:
    bool isValid(string s) {
        string st=s;
        int flag=1;
        while(!st.empty()){
            int n=st.size();
            for(int i=0;i<n-2;i++){
                string temp=st.substr(i,3);
                if(temp=="abc"){
                    flag=0;
                    st=st.substr(0,i)+st.substr(i+3,n-i-2);
                    break;
                }
            }
            if(flag && !st.empty()) return false;
            flag=1;
        }
        return true;
    }
};