class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        vector<int> vis(n * n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int curr = q.front();
                q.pop();

                if (curr == n * n)
                    return moves;

                for (int dice = 1; dice <= 6; dice++) {

                    int nxt = curr + dice;

                    if (nxt > n * n)
                        break;

                    int x = nxt - 1;

                    int row = n - 1 - x / n;
                    int col = x % n;

                    if ((x / n) % 2 == 1)
                        col = n - 1 - col;

                    if (board[row][col] != -1)
                        nxt = board[row][col];

                    if (!vis[nxt]) {
                        vis[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};