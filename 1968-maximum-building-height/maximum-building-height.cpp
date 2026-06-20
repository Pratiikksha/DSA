class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (n == 1)
            return 0;
        int l = restrictions.size();
        if (l == 0) {
            return n - 1;
        }
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int maxi = 0;
        int idx = 0;
        int flag = 0;
        for (int i = 1; i < l + 1; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }
        for (int i = l - 1; i > 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }
        for (int i = 1; i <= l; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            int peak = (restrictions[i][1] + restrictions[i - 1][1] + dist) / 2;
            maxi = max(maxi, peak);
        }
        maxi = max(maxi, restrictions.back()[1] + (n - restrictions.back()[0]));
        return maxi;
    }
};