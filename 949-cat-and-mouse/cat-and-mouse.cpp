class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();

        // color[m][c][t]
        // 0 = Draw
        // 1 = Mouse wins
        // 2 = Cat wins
        vector<vector<vector<int>>> color(
            n, vector<vector<int>>(n, vector<int>(2, 0)));

        // degree[m][c][t]
        vector<vector<vector<int>>> degree(
            n, vector<vector<int>>(n, vector<int>(2)));

        // Initialize outdegrees
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][0] = graph[m].size(); // Mouse turn
                degree[m][c][1] = graph[c].size(); // Cat turn

                // Cat cannot move into hole (0)
                for (int x : graph[c]) {
                    if (x == 0) {
                        degree[m][c][1]--;
                    }
                }
            }
        }

        queue<array<int,4>> q;

        // Terminal states

        // Mouse reaches hole
        for (int c = 1; c < n; c++) {
            color[0][c][0] = 1;
            color[0][c][1] = 1;
            q.push({0, c, 0, 1});
            q.push({0, c, 1, 1});
        }

        // Cat catches mouse
        for (int i = 1; i < n; i++) {
            color[i][i][0] = 2;
            color[i][i][1] = 2;
            q.push({i, i, 0, 2});
            q.push({i, i, 1, 2});
        }

        while (!q.empty()) {
            auto [m, c, turn, result] = q.front();
            q.pop();

            // Find all parent states
            if (turn == 0) {
                // Previous was Cat's turn
                for (int pc : graph[c]) {
                    if (pc == 0) continue;

                    if (color[m][pc][1] != 0) continue;

                    // Cat can choose winning move
                    if (result == 2) {
                        color[m][pc][1] = 2;
                        q.push({m, pc, 1, 2});
                    }
                    else {
                        degree[m][pc][1]--;
                        if (degree[m][pc][1] == 0) {
                            color[m][pc][1] = 1;
                            q.push({m, pc, 1, 1});
                        }
                    }
                }
            }
            else {
                // Previous was Mouse's turn
                for (int pm : graph[m]) {

                    if (color[pm][c][0] != 0) continue;

                    // Mouse can choose winning move
                    if (result == 1) {
                        color[pm][c][0] = 1;
                        q.push({pm, c, 0, 1});
                    }
                    else {
                        degree[pm][c][0]--;
                        if (degree[pm][c][0] == 0) {
                            color[pm][c][0] = 2;
                            q.push({pm, c, 0, 2});
                        }
                    }
                }
            }
        }

        return color[1][2][0];
    }
};