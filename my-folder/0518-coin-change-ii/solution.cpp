class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[5005];
        dp[0] = 1;
        for ( auto c : coins ) {
            int ways = 0;
            for ( int j = c ; j <= amount ; ++j ) {
                dp[j] += dp[j-c];
            }
        }
        return dp[amount];
    }
};
