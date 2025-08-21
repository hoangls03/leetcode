class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> sum(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                int l = 0, up = 0, op = 0;
                if ( i > 0 ) up = sum[i-1][j];
                if ( j > 0 ) l = sum[i][j-1];
                if ( i > 0 && j > 0 ) op = sum[i-1][j-1];
                sum[i][j] = up + l - op + mat[i][j];
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = i ; j < m ; ++j ) {
                int pre = 0,count = 0;
                for ( int z = 0 ; z < n ; ++z ) {
                    int row = 0;
                    if ( i > 0 ) row = sum[i-1][z];                    
                    if ( sum[j][z] - row - pre == j - i + 1 ) {
                        count++;
                    } else {
                        ans += count*(count + 1)/2;
                        count = 0;
                    }
                    pre = sum[j][z] - row;
                }
                ans += count*(count + 1)/2;
            }
        }
        return ans;
    }
};
