class Solution {
public:
    int minFlips(string target) {
        // if (target == "1")
        //     return 1;
        // else if (target == "0")
            // return 0;
        int n = target.size();
        int c = 0;
        int i = 0;
        char s = '0';
        while (i < n) {
            if (target[i] == s) {
                i++;
                continue;
            } else {
                c++;
                if (target[i] == '0') {
                    s = '0';
                } else {
                    s = '1';
                }
            }
            i++;
        }
        return c;
    }
};