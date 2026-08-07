class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> ans(n, -1);

        unordered_map<int, int> lastRain;
        set<int> dryDays;

        for (int i = 0; i < n; i++) {

            if (rains[i] == 0) {
                dryDays.insert(i);
                ans[i] = 1;            // default value
            }
            else {

                int lake = rains[i];

                // Lake already full
                if (lastRain.count(lake)) {

                    // Find first dry day after previous rain
                    auto it = dryDays.upper_bound(lastRain[lake]);

                    if (it == dryDays.end())
                        return {};

                    ans[*it] = lake;
                    dryDays.erase(it);
                }

                lastRain[lake] = i;
            }
        }

        return ans;
    }
};