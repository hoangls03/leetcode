class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<long long>> f(m,vector<long long>(n,-1e18));
        for ( int j = 0 ; j < n ; ++j ) {
            f[0][j] = points[0][j];
        }
        long long ans = -1e18;
        for ( int i = 1 ; i < m ; ++i ) {
            vector<long long> l(n,0);
            for ( int j = 0 ; j < n ; ++j ) {
                l[j] = ( j == 0 ) ? f[i-1][j] : max(l[j-1]-1,1LL*f[i-1][j]);
                f[i][j] = max(f[i][j],points[i][j] + l[j]);
            }
            vector<long long> r(n,0);
            for ( int j = n - 1 ; j >= 0 ; --j ) {
                r[j] = ( j == n - 1 ) ? f[i-1][j] : max(r[j+1]-1,1LL*f[i-1][j]);
                f[i][j] = max(f[i][j],points[i][j] + r[j]);
            }
        }
        for ( int j = 0 ; j < n ; ++j ) {
            ans = max(ans,f[m-1][j]);
        }
        return ans;
    }
};
