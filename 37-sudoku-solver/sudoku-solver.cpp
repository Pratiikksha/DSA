class Solution {
public:
    bool next_location(vector<vector<char>>& board, int& i, int& j) {
        for (int i1 = 0; i1 < 3; ++i1) {
            for (int j1 = 0; j1 < 3; ++j1) {
                for (int i2 = 0; i2 < 3; ++i2) {
                    for (int j2 = 0; j2 < 3; ++j2) {
                        i = 3 * i1 + i2;
                        j = 3 * j1 + j2;
                        // return 'true' if we find an
                        // unoccupied entry
                        if (board[i][j] == '.')
                            return true;
                    }
                }
            }
        }
        return false; // all the entries are occupied
    }
    bool isValid(char no, int x, int y, vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (board[i][y] == no)
                return false;
            if (board[x][i] == no)
                return false;
        }
        int r = (x / 3) * 3;
        int c = (y / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r + i][c + j] == no) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int i,j;
        if(!next_location(board,i,j)){
            return true;
        }
        for(int k=1;k<10;k++){
            if(isValid('0'+k,i,j,board)){
                board[i][j]='0'+k;
                if(solve(board))
                return true;
                else{
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        bool ans=solve(board);
        return;
    }
};