class Solution {
public:
    bool canEat(int k, int h, vector<int>& piles) {
        long long hrs = 0;
        for (int i : piles) {
            hrs += (i+k-1)/k;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int o) {
        int maxi = 0;
        for (int i : piles) {
            maxi = max(maxi, i);
        }
        int h = maxi;
        int l = 1;
        int mid = 0;
        while (l <= h) {
            mid = (l + h) / 2;
            if (canEat(mid, o, piles)) {
                h = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};