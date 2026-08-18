class Solution {
public:
    int  square(int num){
        int ans=0;
        while(num>0){
            int r=num%10;
            ans+=r*r;
            num=num/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow=square(n);
        int fast=square(square(n));
        while(slow!=fast){
            slow=square(slow);
            fast=square(square(fast));
        }
        return fast==1;
    }
};