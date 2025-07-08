class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>> dp(n,vector<int>(k + 1,0));
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i != n - 1 ) {
                for ( int j = 1 ; j <= k ; ++j ) {
                    dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
                }
            }
            for ( int j = k ; j >= 1 ; --j ) {
                dp[i][j] = max(dp[i][j],dp[i][j-1] + events[i][2]);
            }
            int l = i + 1;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( events[mid][0] > events[i][1] ) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if ( pos != - 1 ) {
                for ( int j = 1 ; j <= k ; ++j ) {
                    dp[pos][j] = max(dp[pos][j],dp[i][j]);
                }
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 1 ; j <= k ; ++j ) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
