class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                int k = __builtin_popcount(i) + __builtin_popcount(j);
                if (k == turnedOn) {
                    string time = to_string(i) + ":";

                    if (j< 10)
                        time += "0";

                    time += to_string(j);

                    result.push_back(time);
                }
            }
        }
        return result;
    }
};