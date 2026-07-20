class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> newGrid(m,vector<int>(n,0));
        newGrid = grid;
        while ( k-- ) {
            for ( int i = 0 ; i < m ; ++i ) {
                for ( int j = 0 ; j < n ; ++j ) {
                    if ( j == 0 ) {
                        if ( i == 0 ) {
                            newGrid[i][j] = grid[m-1][n-1];
                        } else {
                            newGrid[i][j] = grid[i-1][n - 1];
                        }
                    } else {
                        newGrid[i][j] = grid[i][j-1];
                    }
                }
            }
            grid = newGrid;
        }
        return newGrid;
    }
};
