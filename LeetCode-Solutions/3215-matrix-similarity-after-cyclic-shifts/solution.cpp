class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> grid(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                grid[i][j] = mat[i][j]; 
            }
        }
        while ( k-- ) {
            vector<vector<int>> tmp(m,vector<int>(n,0));
            for ( int i = 0 ; i < m ; ++i ) {
                if ( i % 2 == 0 ) {
                    for ( int j = 0 ; j < n ; ++j ) {
                        tmp[i][j] = grid[i][(j + 1)%n];
                    }
                } else {
                    for ( int j = n - 1; j >= 0 ; --j ) {
                        tmp[i][j] = grid[i][(j - 1 + n)%n];
                    }
                }
            }
            grid = tmp;
        }
        for ( int i = 0 ;  i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] != mat[i][j] ) {
                    return false;
                }
            }
        }
        return true;
    }
};
