class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position (closest to target first)
        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double fleetTime = 0;

        for (auto &[pos, time] : cars) {
            if (time > fleetTime) {
                // Can't catch the fleet ahead
                fleets++;
                fleetTime = time;
            }
            // else: merges into the fleet ahead
        }

        return fleets;
    }
};