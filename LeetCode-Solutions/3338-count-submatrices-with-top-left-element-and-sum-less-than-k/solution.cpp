class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> sum(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            int curSum = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                curSum += grid[i][j];
                sum[i][j] = (i > 0) ? sum[i-1][j] : 0;
                sum[i][j] += curSum;
                if ( sum[i][j] <= k ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
