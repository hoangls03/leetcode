class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n+5,0));
        vector<int> sum(n,0);
        sum[n-1] = piles[n-1];
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            sum[i] = sum[i+1] + piles[i];
        }
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            for ( int m = 1 ; m <= n ; ++m ) {
                for ( int x = 1 ; x <= 2*m ; ++x ) {
                    int temp = max(x,m);
                    int val = ( i + x >= n ) ? sum[i] : sum[i] - dp[i+x][temp]; 
                    dp[i][m] = max(dp[i][m],val);
                }
            }
        }
        return dp[0][1];
    }
};
