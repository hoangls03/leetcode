class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                ans[i][j] = grid[i][j];
            }
        }
        for ( int i = x ; i < x + k ; ++i ) {
            for ( int j = y ; j < y + k ; ++j ) {
                ans[i][j] = grid[x + k - 1 - (i - x)][j];
            }
        }
        return ans;
    }
};
