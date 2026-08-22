class Solution {
public:
    string transform(string st){
        string s="";
        int n=st.size();
        for(int i=0;i<n;i++){
            int j=i;
            int cnt=0;
            while(j<n && st[j]==st[i]){
                cnt++;
                j++;
            }
            s=s+to_string(cnt);
            s=s+st[i];
            i=j-1;
        }
        return s;
    }
    string countAndSay(int n) {
        if (n==1) return "1";
       return transform(countAndSay(n-1));
    }
};