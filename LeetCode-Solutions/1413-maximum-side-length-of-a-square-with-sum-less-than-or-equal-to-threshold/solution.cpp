class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<long long>> sum(m,vector<long long>(n,0));
        sum[0][0] = mat[0][0];
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                long long l = 0;
                long long r = 0;
                long long u = 0;
                if ( i - 1 >= 0 ) {
                    l = sum[i-1][j];
                }
                if ( j - 1 >= 0 ) {
                    r = sum[i][j-1];
                }
                if ( i - 1 >= 0 && j - 1 >= 0 ) {
                    u = sum[i-1][j - 1];
                }
                long long v = l + r + mat[i][j] - u;
                sum[i][j] = v;
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                for ( int k = 0 ; k < min(m,n) ; ++k ) {
                    if ( i + k < m && j + k < n ) {
                        long long l = 0;
                        long long r = 0;
                        long long u = 0;
                        if ( i - 1 >= 0 ) {
                            l = sum[i-1][j + k];
                        }
                        if ( j - 1 >= 0 ) {
                            r = sum[i + k][j-1];
                        }
                        if ( i - 1 >= 0 && j - 1 >= 0 ) {
                            u = sum[i-1][j - 1];
                        }
                        long long v = sum[i+k][j+k] - l - r + u;
                        if ( v <= threshold ) {
                            ans = max(ans,k + 1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
