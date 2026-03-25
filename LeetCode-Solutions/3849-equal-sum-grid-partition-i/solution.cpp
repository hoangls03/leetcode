class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                sum += grid[i][j];
            }
        }
        long long localSum = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                localSum += grid[i][j];
            }
            if ( localSum == sum - localSum ) {
                return true;
            }
        }
        localSum = 0;
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                localSum += grid[i][j];
            }
            if ( localSum == sum - localSum ) {
                return true;
            }
        }
        return false;
    }
};
