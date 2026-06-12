class Solution {
public:
    bool canBeShipped(int x, vector<int>& weights, int days) {
        int curr = 0;
        int totalDays = 0;
        int i=0;
        int n=weights.size();
        while(i<n) {
            if (curr + weights[i] <= x) {
                curr += weights[i];
                i++;
            } else {
                totalDays++;
                curr = 0;
            }
        }
        totalDays++;
        return totalDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int h = accumulate(weights.begin(), weights.end(), 0);
        if (days == 1)
            return h;
        int l = *max_element(weights.begin(), weights.end());
        if (days == weights.size())
            return l;
        while (l <h) {
            int mid = (l + h) / 2;
            if (canBeShipped(mid, weights, days)) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
;