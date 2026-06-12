class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for (int i : bills) {
            if (i == 5) {
                mp[i]++;
            }
            if (i == 10) {
                if (mp.count(5)) {
                    mp[5]--;
                    mp[10]++;
                    if (mp[5] == 0) {
                        mp.erase(5);
                    }
                } else {
                    return false;
                }
            }
            if (i == 20) {
                if (mp.count(5)) {
                    if (mp.count(10)) {
                        mp[10]--;
                        mp[5]--;
                        if (mp[5] == 0) {
                            mp.erase(5);
                        }
                        if (mp[10] == 0) {
                            mp.erase(10);
                        }
                    } else {
                        if (mp[5] >= 3) {
                            mp[5] -= 3;
                            if (mp[5] == 0) {
                                mp.erase(5);
                            }
                        } else
                            return false;
                    }
                } else
                    return false;
            }
        }
        return true;
    }
};