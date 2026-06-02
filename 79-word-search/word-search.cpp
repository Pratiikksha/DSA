class Solution {
public:
    bool solve(int x, int y, string &word,
               vector<vector<char>>& board,
               vector<vector<int>>& vis,
               int idx) {

        if(idx == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        vis[x][y] = 1;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 &&
               nx<n && ny<m &&
               !vis[nx][ny] &&
               board[nx][ny]==word[idx]) {

                if(solve(nx,ny,word,board,vis,idx+1))
                    return true;
            }
        }

        vis[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(board[i][j]==word[0]) {

                    if(solve(i,j,word,board,vis,1))
                        return true;
                }
            }
        }

        return false;
    }
};