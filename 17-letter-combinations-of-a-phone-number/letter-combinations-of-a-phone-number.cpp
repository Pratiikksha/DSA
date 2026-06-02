class Solution {
public:
    void solve(int idx, string curr, vector<vector<string>>& mp, string& digits,
               vector<string>& ans, int& d) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        // if (d == 0) {
        //     return;
        // }
        for (int i = 0; i < mp[idx].size(); i++) {
            curr = mp[idx][i] + curr;
            int y = (d / 10);
            int x= (d % 10) - 2;
            solve(x, curr, mp, digits, ans, y);
            curr = curr.substr(1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> mp = {{"a", "b", "c"}, {"d", "e", "f"},
                                     {"g", "h", "i"}, {"j", "k", "l"},
                                     {"m", "n", "o"}, {"p", "q", "r", "s"},
                                     {"t", "u", "v"}, {"w", "x", "y", "z"}};
        int n = digits.size();
        vector<string> ans;
        string curr = "";
        int d = stoi(digits);
        int y = (d / 10);
        int x=(d % 10)- 2;
        solve(x, curr, mp, digits, ans, y);
        return ans;
    }
};