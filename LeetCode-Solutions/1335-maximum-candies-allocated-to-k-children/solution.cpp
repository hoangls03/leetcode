class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = 1e7;
        int ans = 0;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            long long res = 0;
            for ( auto i : candies ) {
                res += 1LL*i/mid;
            }
            if ( res >= k ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
