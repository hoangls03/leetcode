class Solution {
public:
    bool ok( int x, int y, char num, vector<vector<char>>& board) {
        for ( int i = 0 ; i < 9 ; ++i ) {
            if ( board[x][i] == num || board[i][y] == num ) {
                return false;
            }
        }
        int blockX = (x/3)*3;
        int blockY = (y/3)*3;
        for ( int i = blockX ; i < blockX + 3 ; ++i ) {
            for ( int j = blockY ; j < blockY + 3 ; ++j ) {
                if ( board[i][j] == num ) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<vector<char>> solve(int x, int y, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int newX = x;
        int newY = y + 1;
        if ( newY >= n ) {
            newY = 0;
            newX++;
        }
        if ( x == 9 ) {
            return board;
        }
        if ( board[x][y] != '.' ) {
            return solve(newX,newY,board);
        }
        for ( char i = '1' ; i <= '9' ; ++i ) {
            if ( ok(x,y,i,board) ) {
                board[x][y] = i;
                vector<vector<char>> res = solve(newX,newY,board);
                if ( res.size() ) {
                    return res;
                }
                board[x][y] = '.';
            }
        }
        return {};
    }
    void solveSudoku(vector<vector<char>>& board) {
        board = solve(0,0,board);
    }
};
