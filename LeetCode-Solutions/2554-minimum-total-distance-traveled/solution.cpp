class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int n = robot.size();
        int m = factory.size();
        long long oo = 1e13;
        
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(n+2,oo)));
        long long ans = oo;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i == 0 ) {
                for ( int j = 0 ; j < m ; ++j ) {
                    if ( factory[j][1] >= 1 ) dp[i][j][1] = abs(factory[j][0]-robot[i]);
                }
            } else {
                for ( int j = 0 ; j < m ; ++j ) {

                    for ( int k = 1 ; k <= factory[j][1] ; ++k ) {
                        if ( k == 1  ) {
                            
                            if ( j > 0 ) {
                                for ( int z = 0 ; z <= j - 1 ; ++z ) {
                                    for ( int o = 1 ; o <= factory[z][1] ; ++o ) {
                                        if ( dp[i-1][z][o] != oo ) {
                                            dp[i][j][k] = min(dp[i][j][k],dp[i-1][z][o] + abs(factory[j][0]-robot[i]));
                                        }
                                    }
                                }
                            }
                        } else {
                            if ( dp[i-1][j][k-1] != oo ) {
                                dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k-1] + abs(factory[j][0]-robot[i]));
                            }
                        }
                        
                    }
                }
            }
        }
        for ( int j = 0 ; j < m ; ++j ) {
            for ( int k = 1 ; k <= factory[j][1] ; ++k ) {
                ans = min(ans,dp[n-1][j][k]);
            }
        }
        return ans;
    }
};
