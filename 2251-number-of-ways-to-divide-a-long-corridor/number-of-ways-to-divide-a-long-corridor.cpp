class Solution {
public:
    int numberOfWays(string corridor) {

        const int MOD = 1e9 + 7;

        // Count total seats
        int seats = 0;
        for (char c : corridor)
            if (c == 'S')
                seats++;

        // Impossible if no seats or odd number of seats
        if (seats == 0 || seats % 2)
            return 0;

        long long ans = 1;

        int seatCnt = 0;
        int plants = 0;

        for (char c : corridor) {

            if (c == 'S') {
                seatCnt++;

                // Beginning of a new pair (3rd, 5th, 7th... seat)
                if (seatCnt > 2 && seatCnt % 2 == 1) {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0;
                }
            }
            else { // Plant

                // Count plants only after finishing a pair
                if (seatCnt >= 2 && seatCnt % 2 == 0)
                    plants++;
            }
        }

        return ans;
    }
};