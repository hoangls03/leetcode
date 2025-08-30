class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
       
        for ( int i = 0 ; i < m ; i += 3 ) {
            for ( int j = 0 ; j < n ; j += 3 ) {
                vector<int> mark('9' + 1,0);
                for ( int u = i ; u <= i + 2 ; ++u ) {
                    for ( int v = j ; v <= j + 2 ; ++v ) {
                        mark[board[u][v]]++;
                    }
                }
                for ( int u = '1' ; u <= '9' ; ++u ) {
                    if ( mark[u] >= 2 ) {
                        return false;
                    }
                }
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            vector<int> mark('9' + 1,0);
            for ( int j = 0 ; j < n ; ++j ) {
                mark[board[i][j]]++;
            }
            for ( int j = '1' ; j <= '9' ; ++j ) {
                if ( mark[j] >= 2 ) return false;
            }
        }
        for ( int j = 0 ; j < n ; ++j ) {
            vector<int> mark('9' + 1,0);
            for ( int i = 0 ; i < m ; ++i ) {
                mark[board[i][j]]++;
            }
            for ( int i = '1' ; i <= '9' ; ++i ) {
                if ( mark[i] >= 2 ) return false;
            }
        }
        return true;
    }
};
