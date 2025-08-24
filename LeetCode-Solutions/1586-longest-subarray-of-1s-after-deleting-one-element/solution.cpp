class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        int ans = 0;
        vector<int> sum(n,0);
        sum[0] = nums[0];
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + nums[i];
        }
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            bool ok = false;
            for ( int i = 0 ; i + mid - 1< n && !ok ; ++i ) {
                if ( sum[i+mid-1] - sum[i] + nums[i] >= mid - 1 ) {
                    ok = true;
                }
            }
            if ( ok ) {
                ans = max(ans,mid - 1);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
