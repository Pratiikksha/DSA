class Solution {
public:
    int maxNumberOfFamilies(int k, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        // Store reserved seats row-wise
        for (auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }

        int ans = 0;

        // Process only rows having reservations
        for (auto &[row, seats] : mp) {
            
            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat)) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat)) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        // Rows with no reservations can always fit 2 families
        int unaffectedRows = k - mp.size();
        ans += unaffectedRows * 2;

        return ans;
    }
};