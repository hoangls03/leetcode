class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        stoneValue.push_back(0);
        vector<int> dp(n + 2,-1e9);
        dp[n] = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            int val = 0;
            for ( int j = 1 ; j <= 3 ; ++j ) {
                if ( i + j - 1 <= n - 1 ) val += stoneValue[i + j - 1];
                if ( i + j <= n ) {
                    dp[i] = max(dp[i],val - dp[i + j]);
                }
            }
        }
        if ( dp[0] < 0 ) return "Bob";
        if ( dp[0] > 0 ) return "Alice";
        return "Tie";
    }
};
