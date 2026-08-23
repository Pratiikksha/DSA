class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.size();
        int j=n-1;
        while(i<j){
            
            while(i<j && (tolower(s[i])<'a' || tolower(s[i])>'z') && (s[i]<'0' || s[i]>'9')){
                i++;
            }
            while(j>i && (tolower(s[j])<'a' || tolower(s[j])>'z') && (s[j]<'0' || s[j]>'9')){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};