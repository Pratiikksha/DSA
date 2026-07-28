class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        string left="";
        string middle="";
        for(int i=0;i<26;i++){
            if(freq['a'+i]%2){
                middle='a'+i;
            }
            int len=freq['a'+i]/2;
            left+=string(len,'a'+i);
        }
        string res=left+middle;
        reverse(left.begin(),left.end());
        return res+left;
    }
};