class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=0;
        while(i<j){
            int amt=(j-i)*min(height[i],height[j]);
            maxi=max(maxi,amt);
            if(height[i]<height[j]){
                i++;
            }
            else j--;
        }
        return maxi;
    }
};