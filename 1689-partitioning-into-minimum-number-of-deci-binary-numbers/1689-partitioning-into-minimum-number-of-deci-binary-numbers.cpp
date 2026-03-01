class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
       for(char s:n){
        maxi=max(maxi,s-'0');
       }
       return maxi;
    }
};