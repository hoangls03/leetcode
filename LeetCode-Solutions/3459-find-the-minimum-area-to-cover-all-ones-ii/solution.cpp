const int oo = 1e8;
class Solution {
public:
    int sumGrid( vector<vector<int>>& grid, int u, int d, int l, int r ) {
        int m = grid.size();
        int n = grid[0].size();
        int minRow = m, maxRow = 0, minCol = n, maxCol = 0;
        for ( int i = u ; i <= d ; ++i ) {
            for ( int j = l ; j <= r ; ++j ) {
                if ( grid[i][j] == 1 ) {
                    minRow = min(minRow,i);
                    maxRow = max(maxRow,i);
                    minCol = min(minCol,j);
                    maxCol = max(maxCol,j);
                }
            }
        }
        if ( minRow > maxRow ) return oo;
        return (maxRow - minRow + 1)*(maxCol - minCol + 1);
    } 
    vector<vector<int>> rotate(vector<vector<int>>& grid ) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rotGrid(n,vector<int>(m,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                rotGrid[n - j - 1][i] = grid[i][j];
            }
        }
        return rotGrid;
    }
    int cal( vector<vector<int>>& grid ) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = m*n;
        for ( int i = 0 ; i < m - 1 ; ++i ) {
            for ( int j = 0 ; j < n - 1 ; ++j ) {
                ans = min({ans,
                           sumGrid(grid,0,i,0,n - 1) + sumGrid(grid,i + 1,m - 1,0,j) + sumGrid(grid,i + 1,m - 1,j + 1,n - 1),
                           sumGrid(grid,0,i,0,j) + sumGrid(grid,0,i,j + 1,n - 1) + sumGrid(grid,i + 1,m - 1,0,n-1),
                            });
            }
        }
        for ( int i = 0 ; i < m - 2 ; ++i ) {
            for ( int j = i + 1 ; j < m - 1 ; ++j ) {
                ans = min(ans,sumGrid(grid,0,i,0,n-1) + sumGrid(grid,i + 1,j,0,n - 1) + sumGrid(grid,j + 1,m - 1,0,n - 1));
            }
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& grid) {
        auto rot = rotate(grid);
        return min(cal(grid),cal(rot));
    }
};
