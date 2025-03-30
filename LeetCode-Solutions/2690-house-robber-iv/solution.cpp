class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int r = 1e9;
        int ans = 1e9;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            int n = nums.size();
            int pos = -2;
            int res = 0;
            for ( int i = 0 ; i < n ; ++i ) {
                if ( nums[i] <= mid && i - pos >= 2 ) {
                    pos = i;
                    res++;
                }
            }
            if ( res >= k ) {
                ans = min(ans,mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
