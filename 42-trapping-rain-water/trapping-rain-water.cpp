class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==1) return 0;
        int leftMax=height[0];
        int rightMax=height[n-1];
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r && l<n-1 && r>0){
            if(leftMax<rightMax){
                int i=height[l];
                if(i<leftMax){
                    ans+=leftMax-i;
                }
                l++;
                leftMax=max(height[l],leftMax);
            }else{
                int i=height[r];
                if(i<rightMax){
                    ans+=rightMax-i;
                }
                r--;
                rightMax=max(height[r],rightMax);
            }
        }
        return ans;
    }
};