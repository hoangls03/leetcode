class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        /*for ( auto i : nums ) {
            cout<<i<<" ";
        }
        cout<<'\n';
        */
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(5,1e10));
        long long ans = 1e9;
        if ( n <= 3 ) return 0;
        dp[0][1] = nums[n-1] - nums[1];
        dp[n-1][1] = nums[n-2] - nums[0];
        dp[0][2] = nums[n-2] - nums[1];
        dp[n-1][2] = nums[n-2] - nums[1];
        ans = min({dp[0][1],dp[0][2],dp[n-1][1],dp[n-1][2]});
        //cout<<ans<<'\n';
        for ( int i = 1 ; i < 3 ; ++i ) {
            for ( int j = i + 1 ; j <= 3 ; ++j ) {
                dp[i][j] = min(dp[i][j],dp[i-1][j-1] + nums[i] - nums[i+1]);
                ans = min(ans,dp[i][j]);
            }
        }
        //cout<<dp[0][2]<<"here"<<'\n';
        //cout<<dp[n-1][1]<<'\n';
        for ( int i = n - 2 ; i >= n - 3 ; --i ) {
            for ( int j = (n - (n-2)) ; j <= 3 ; ++j ) {
                dp[i][j] = min(dp[i][j],dp[i+1][j-1]-nums[i]+nums[i-1]);
                ans = min(ans,dp[i][j]);
               // cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
            }
        }
        return ans;
    }
};
