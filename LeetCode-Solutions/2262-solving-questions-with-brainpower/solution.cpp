class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,0);
        dp[n-1] = questions[n-1][0];
        for ( int i = n - 2 ; i >= 0 ; --i ) {
            int points = questions[i][0];
            int brainpower = questions[i][1];

            int next = i + brainpower + 1;

            long long res = points + ( next < n ? dp[next] : 0 );

            dp[i] = max(res,dp[i+1]);
        }

        return dp[0];
    }
};
