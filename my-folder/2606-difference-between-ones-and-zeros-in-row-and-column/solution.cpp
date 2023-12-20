class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int zeroRow,zeroCol;
        vector<int> oneRow(m,0);
        vector<int> oneCol(n,0);

        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( j == 0 ) oneRow[i] = grid[i][j];
                else oneRow[i] = oneRow[i] + grid[i][j];
            }
        }
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                if ( i == 0 ) oneCol[j] = grid[i][j];
                else oneCol[j] = oneCol[j] + grid[i][j];
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                zeroRow = m - oneRow[i];
                zeroCol = n - oneCol[j];
                grid[i][j] = oneRow[i] + oneCol[j] - zeroRow - zeroCol;
            }
        }
        return grid;
    }
};
