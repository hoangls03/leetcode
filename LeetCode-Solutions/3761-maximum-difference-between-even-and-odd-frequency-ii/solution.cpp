class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<vector<int>> mark('4' + 1, vector<int>(n + 1,0));
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = '0' ; j <= '4' ; ++j ) {
                mark[j][i+1] = mark[j][i];
            }
            mark[s[i]][i+1]++;
        }
        int ans = -1e9;
        for ( int i = '0' ; i <= '4' ; ++i ) {
            if ( mark[i][n] == 0 ) continue;
            for ( int j = '0' ; j <= '4' ; ++j ) {
                if ( mark[j][n] == 0 || i == j ) {
                    continue;
                }
                int tmp = -1e9;
                int dp[2][2] = {{-tmp, -tmp},{-tmp, -tmp}};
                int cur = 0, cur1 = 0, prev = 0, prev1 = 0,l = 0;
                for ( int r = k - 1 ; r < n ; ++r ) {
                    cur = mark[i][r+1];
                    cur1 = mark[j][r+1];

                    while ( r - l + 1 >= k && cur1 - prev1 >= 2 ) {
                        dp[prev&1][prev1&1] = min(dp[prev&1][prev1&1],prev - prev1);
                        prev = mark[i][l+1];
                        prev1 = mark[j][l+1];
                        l++;
                    }

                    ans = max(ans,cur - cur1 - dp[1-(cur & 1)][cur1 & 1]);
                }
            }
        }
        return ans;
    }
};
