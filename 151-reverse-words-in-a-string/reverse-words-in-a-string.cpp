class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string st = "";
        int j = 0;
        while (s[j] == ' ') {
            j++;
        }
        int n=s.size();
        for (int i = j; i < n; i++) {
            if (s[i] != ' ') {
                st += s[i];
            } else {
                while (i<=n-1 && s[i] == ' ') {
                    i++;
                }
                ans=st+' '+ans;
                st="";
                i--;
            }
        }
        ans=st+' '+ans;
        j=0;
        while (ans[j] == ' ') {
            j++;
        }
        int l=ans.size();
        return ans.substr(j,l-j-1);
    }
}
;