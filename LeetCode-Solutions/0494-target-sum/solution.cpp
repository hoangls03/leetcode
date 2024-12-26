class Solution {
public: 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for ( auto i : nums ) {
            sum += i;
        }
        int diff = sum - target;
        if ( diff < 0 || diff & 1 ) return 0;
        diff /= 2;
        vector<vector<int>> dp(n+1,vector<int>(diff + 1,0));
        dp[0][0] = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            for ( int j = 0 ; j <= diff ; ++j ) {
                dp[i][j] = dp[i-1][j];
                if ( j >= nums[i-1] ) {
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        ans = dp[n][diff];
        return ans;
    }
};
