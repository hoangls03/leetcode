class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                int tmp = 0;
                if ( i > 0 && j > 0 ) tmp = dp[i-1][j-1];
                if ( nums1[i] == nums2[j] ) {
                    dp[i][j] = max(dp[i][j],tmp + 1);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
