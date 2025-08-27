const int dx[] = {-1,-1,1,1};
const int dy[] = {-1,1,1,-1};
class Solution {
public:
    int cal( int x, int y, int turn, int dir, int next, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        int xnew = x + dx[dir];
        int ynew = y + dy[dir];
        int m = grid.size();
        int n = grid[0].size();
        if ( xnew < 0 || ynew < 0 || xnew >= m || ynew >= n || grid[xnew][ynew] != next ) {
            return 0;
        }
        if ( dp[xnew][ynew][turn][dir] != -1 ) {
            return dp[xnew][ynew][turn][dir];
        }
        int res = cal(xnew,ynew,turn,dir,2 - next,grid,dp);
        if ( turn ) {
            res = max(res,cal(xnew,ynew,0,(dir + 1)%4,2-next,grid,dp));
        }
        dp[xnew][ynew][turn][dir] = res + 1;
        return dp[xnew][ynew][turn][dir];
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(5,-1))));
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( grid[i][j] == 1 ) {
                    for ( int k = 0 ; k < 4 ; ++k ) {
                        ans = max(ans,cal(i,j,1,k,2,grid,dp) + 1);
                    }
                }
            }
        }
        return ans;
    }
};
