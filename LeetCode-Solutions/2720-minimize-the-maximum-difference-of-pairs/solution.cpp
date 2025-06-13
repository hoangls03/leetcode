class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        vector<int> tmp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for ( int i = 1 ; i < n ; ++i ) {
            tmp.push_back(nums[i] - nums[i-1]);
        }
        int l = 0;
        int r = 1e9;
        int ans = 1e9 + 5;
        int m = tmp.size();
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            vector<int> dp(m,0);
            for ( int i = 0 ; i < m ; ++i ) {
                if ( i >= 2 ) {
                    dp[i] = dp[i-2];
                }
                if ( tmp[i] <= mid ) {
                    dp[i]++;
                }
                if ( i >= 1 ) {
                    dp[i] = max(dp[i],dp[i-1]);
                }
            }
            if ( m - 1 >= 0 && dp[m - 1] >= p ) {
                ans = min(ans,mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if ( ans == 1e9 + 5 ) ans = 0;
        return ans;
    }
};
