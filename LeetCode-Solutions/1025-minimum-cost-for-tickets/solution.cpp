class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366,1e9);
        for ( int i = 0 ; i < n ; ++i ) {
            int day = days[i];
            int prev = 0;
            if ( i != 0 ) prev = dp[days[i-1]];
            dp[day] = min(dp[day],prev + costs[0]);
            for ( int j = day ; j <= min(day + 6,365) ; ++j ) {
                dp[j] = min(dp[j],prev + costs[1]);
            }
            for ( int j = day ; j <= min(day + 29,365) ; ++j ) {
                dp[j] = min(dp[j],prev + costs[2]);
            }
        }
        return dp[days[n-1]];
    }
};
