const int oo = 1e9 + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        vector<int> pow2(n,1);
        for ( int i = 1 ; i < n ; ++i ) {
            pow2[i] = 1LL*pow2[i-1]*2%oo;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            int l = i;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = (l + r)>>1;
                if ( nums[mid] + nums[i] <= target ) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ( pos != -1 ) {
                ans = (ans + pow2[pos - i])%oo;

            }
        }
        return ans;
    }
};
