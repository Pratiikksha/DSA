class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = -1, sy = -1;
        int total = 0;

        // Give every litter cell an index
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = total++;
                }
            }
        }

        int fullMask = (1 << total) - 1;

        // state = {x, y, energyLeft, mask}
        queue<array<int, 4>> q;

        q.push({sx, sy, energy, 0});

        // visited[x][y][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << total, false)
                )
            )
        );

        visited[sx][sy][energy][0] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                // If all litter is collected
                if (mask == fullMask) {
                    return steps;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Outside grid / wall
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n ||
                        classroom[nx][ny] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy
                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    // Collect litter
                    int nmask = mask;

                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << id[nx][ny]);
                    }

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    if (!visited[nx][ny][ne][nmask]) {
                        visited[nx][ny][ne][nmask] = true;
                        q.push({nx, ny, ne, nmask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};