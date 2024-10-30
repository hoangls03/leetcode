class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        vector<int> dpR(n,1e9);
        for ( int i = 0 ; i < n ; ++i ) {
            dp[i] = i;
            dpR[i] = n - i - 1;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                if ( nums[i] > nums[j] ) {
                    dp[i] = min(dp[i],dp[j] + i - j - 1);
                }
            }
        } 
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                if ( nums[i] > nums[j] ) {
                    dpR[i] = min(dpR[i],dpR[j] + j - i - 1);
                }
            }
        }
        int ans = 1e9;
        for ( int i = 1 ; i < n - 1 ; ++i ) {
            if ( dp[i] != i && dpR[i] != n - i - 1 ) {
                ans = min(ans,dp[i] + dpR[i]);
            }
        }
        return ans;
    }
};
