class Solution {
public:
    void create(int l, int h, int low, int high, vector<int>&scope){
        int done=0;
        for(int i=l;i<=h;i++){
            for(int j=1;j<=10-i;j++){
                int num=0;
                for(int k=j;k<j+i;k++){
                    num=num*10+k;
                }
                if(num>high){
                    done=1;
                    break;
                }
                if(num<low) continue;
                scope.push_back(num);
            }
            if(done) break;
        }
    }
    int numberOfDigits(int x){
        int n=x;
        int cnt=0;
        while(n>0){
            cnt++;
            n=n/10;
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        if(low==high){
            int n=high;
            int last=high%10;
            n=n/10;
            while(n>0){
                int r=n%10;
                if(r!=last-1) return {};
                last=r;
                n=n/10;
            }
            return {high};
        }
        int l=numberOfDigits(low);
        int h=numberOfDigits(high);
        vector<int>scope;
        create(l,h,low,high,scope);
        return scope;
    }
};