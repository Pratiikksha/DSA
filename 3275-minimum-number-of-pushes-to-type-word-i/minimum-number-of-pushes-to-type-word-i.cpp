class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int i=1;
        while(n>=8){
            ans+=(i*8);
            i++;
            n=n-8;
        }
        return ans+(i*n);
    }
};