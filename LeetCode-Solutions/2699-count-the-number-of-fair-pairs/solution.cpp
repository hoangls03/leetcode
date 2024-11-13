class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0, pos = 0, pos1 = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int l = i + 1;
            int r = n - 1;
            long long pos = -1, pos1 = -1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( nums[i] + nums[mid] >= lower ) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            l = i + 1;
            r = n - 1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( nums[i] + nums[mid] <= upper ) {
                    pos1 = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ( pos != -1 && pos1 != -1 ) {
                ans += pos1 - pos + 1;
            }
        }
        return ans;
    }
};
