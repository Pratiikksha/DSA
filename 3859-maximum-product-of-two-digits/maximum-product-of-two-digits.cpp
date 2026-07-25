class Solution {
public:
    int maxProduct(int n) {
        vector<int>v(10,0);
        int i=0;
        int num=n;
        while(num>0){
            v[i++]=num%10;
            num=num/10;
        }
        int maxi=0;
        for(int i=0;i<9;i++){
            for(int j=i+1;j<9;j++){
                if(maxi<v[i]*v[j]){
                    maxi=v[i]*v[j];
                }
            }
        }
        return maxi;
    }
};