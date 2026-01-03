const int oo = 1e9 + 7;
class Solution {
public:
    int numOfWays(int n) {
        vector<vector<vector<vector<long long>>>> dp(n,vector<vector<vector<long long>>>(3,vector<vector<long long>>(3,vector<long long>(3,0))));
        for ( int i = 0 ; i < 3 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                for ( int z = 0 ; z < 3 ; ++z ) {
                    if ( i != j && j != z ) {
                        dp[0][i][j][z] = 1;
                    }
                }
            }
        }
        for ( int l = 1 ; l < n ; ++l ) {
            for ( int i = 0 ; i < 3 ; ++i ) {
                for ( int j = 0 ; j < 3 ; ++j ) {
                    for ( int z = 0 ; z < 3 ; ++z ) {
                        if ( i != j && j != z ) {
                            for ( int iOld = 0 ; iOld < 3 ; ++iOld ) {
                                for ( int jOld = 0 ; jOld < 3 ; ++jOld ) {
                                    for ( int zOld = 0 ; zOld < 3 ; ++zOld ) {
                                        if ( i != iOld && j != jOld && z != zOld ) {
                                            dp[l][i][j][z] = (dp[l][i][j][z] + dp[l-1][iOld][jOld][zOld])%oo;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for ( int i = 0 ; i < 3 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                for ( int z = 0 ; z < 3 ; ++z ) {
                    ans = (ans + dp[n-1][i][j][z])%oo;
                }
            }
        }
        return ans;
    }
};
