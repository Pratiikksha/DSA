class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxi = 0;
        while (i <= j) {
            maxi = max(maxi, (j - i) * min(height[j], height[i]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};