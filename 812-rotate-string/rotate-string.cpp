class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=goal.size();
        int m=s.size();
        if(n!=m) return false;
        string st;
        for(int i=0;i<n;i++){
         st=s.substr(1,n-1);
         st=st+s[0];
         if(st==goal) return true;
         s=st;
        }
        return false;
    }
};