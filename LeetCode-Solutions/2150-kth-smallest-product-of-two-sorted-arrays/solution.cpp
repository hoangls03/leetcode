class Solution {
public:
    long long findPos( vector<int>&nums, long long val, long long k ) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = -1;
        while ( l <= r ) {
            int mid = (l + r) >> 1;
            if ( val*nums[mid] > k ) {
                if ( val < 0 ) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                ans = mid;
                if ( val < 0 ) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        if ( val < 0 && ans != -1 ) {
            ans = n - 1 - ans;
        }
        return ans + 1;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10;
        long long r = 1e10;
        int m = nums1.size();
        int n = nums2.size();
        long long ans = -1e15;
        while ( l <= r ) {
            long long mid = ( l + r ) >> 1LL;
            long long res = 0;
            for ( int i = 0 ; i < m ; ++i ) {
                res += findPos(nums2,nums1[i],mid);
            }
            if ( res >= k ) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
