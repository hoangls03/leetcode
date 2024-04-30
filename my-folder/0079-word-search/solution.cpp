const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
class Solution {
public:
    bool DFS(int i, int j, int m, int n, vector<vector<char>>& board, string word, int pos) {
        if ( pos == word.size() ) return true;
        if ( i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[pos] ) return false;
        char ch = board[i][j];
        board[i][j] = '#';
        bool check = false;
        for ( int k = 0 ; k < 4 ; ++k ) {
            check |= DFS(i+dx[k],j+dy[k],m,n,board,word,pos+1);
        }
        board[i][j] = ch;
        return check;
    } 
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( DFS(i,j,m,n,board,word,0)) return true;
            }
        }
        return false;
    }
};
