class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = 0;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (colors[i] != colors[j]) {
                maxi = max(maxi, j - i);
                break;
            }
            i++;
        }
        i=0;
        while (i <= j) {
            if (colors[i] != colors[j]) {
                maxi = max(maxi, j - i);
                break;
            }
            j--;
        }
        return maxi;
    }
};