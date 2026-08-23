class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;
        for (auto i : points) {
            map<pair<int, int>, int> mp;
            int x = i[0];
            int y = i[1];
            for (auto j : points) {
                if (i == j)
                    continue;
                int nx = j[0];
                int ny = j[1];
                int dx = x - nx;
                int dy = y - ny;
                int hcf = gcd(abs(dx), abs(dy));
                if (dx < 0 && dy < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                pair<int, int> curr;
                if (dx == 0) {
                    mp[{0, 1}]++;
                    curr = {0, 1};
                } else if (dy == 0) {
                    mp[{1, 0}]++;
                    curr = {1, 0};
                } else {
                    curr = {dx / hcf, dy / hcf};
                    mp[curr]++;
                }
                maxi = max(maxi, mp[curr]);
            }
        }
        return maxi+1;
    }
};