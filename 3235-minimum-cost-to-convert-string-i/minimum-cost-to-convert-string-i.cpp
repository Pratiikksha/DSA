class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size())
            return -1;
        vector<vector<int>> dis(26, vector<int>(26, 1e8));
        for (int i = 0; i < 26; i++)
            dis[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            dis[original[i] - 'a'][changed[i] - 'a'] =
                min(dis[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
        long long costTo = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (dis[source[i] - 'a'][target[i] - 'a'] == 1e8)
                    return -1;
                costTo += dis[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return costTo;
    }
};