class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int i=n-1;
        while(i>=0){
            if((num[i]-'0')%2==1){
                break;
            }
            i--;
        }
        int len=i-0+1;
        return num.substr(0,len);
    }
};