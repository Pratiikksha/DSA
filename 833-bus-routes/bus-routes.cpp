class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source,
                              int target) {

        if (source == target)
            return 0;

        // stop -> buses passing through it
        unordered_map<int, vector<int>> stopToBus;

        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        vector<int> visitedBus(routes.size(), 0);

        int busesTaken = 0;

        while (!q.empty()) {

            int sz = q.size();
            busesTaken++;

            while (sz--) {

                int stop = q.front();
                q.pop();

                // Try every bus available at this stop
                for (int bus : stopToBus[stop]) {

                    if (visitedBus[bus])
                        continue;

                    visitedBus[bus] = 1;

                    // Visit every stop on this bus
                    for (int nextStop : routes[bus]) {

                        if (nextStop == target)
                            return busesTaken;

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};