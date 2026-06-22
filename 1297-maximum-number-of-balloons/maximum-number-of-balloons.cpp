class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        if(text.size()<7) return 0;
        for(char c:text){
            if(c=='a') a++;
            else if(c=='b') b++;
            else if(c=='l') l++;
            else if(c=='o') o++;
            else if(c=='n') n++;
        }
        l=l/2;
        o=o/2;
        return min({b,a,l,o,n});
    }
};