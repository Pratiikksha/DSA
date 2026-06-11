class Solution {
public:
    bool canMake(int x,vector<int>& bloomDay,int m,int k){
        int flower=0;
        int bouquets=0;
        for(int i:bloomDay){
            if(i<=x){
                flower++;
                if(flower==k){
                    bouquets++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total=1LL*m*k;
        if(bloomDay.size()<total){
            return -1;
        }
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        if(bloomDay.size()==total){
            return maxi;
        }
        while(maxi>=mini){
            int mid=(maxi+mini)/2;
            if(canMake(mid,bloomDay,m,k)){
                maxi=mid-1;
            }
            else mini=mid+1;
        }
        return mini;
    }
};