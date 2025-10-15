class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        for ( int i = n - 1 ; i >= 1 ; --i ) {
            if ( nums[i] > nums[i-1] ) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        nums[0] = 1;
        vector<int> sum(n,0);
        sum[0] = 1;
        for ( int i = 1 ; i < n ; ++i ) {
            sum[i] = sum[i-1] + nums[i];
        }
        int l = 1;
        int r = n;
        int ans = 0;
        while ( l <= r ) {
            int mid = (l + r)>>1;
            bool ok = false;
            for ( int i = 0; i + 2*mid <= n ; ++i ) {
                if ( sum[i+mid-1] - sum[i] == mid - 1&& sum[i+2*mid-1] - sum[i+mid] == mid - 1) {
                    ok = true;
                    break;
                }
            }
            if ( ok ) {
                ans = max(ans,mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
