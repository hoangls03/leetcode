class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = 1e18;
        long long ans = 0;
        while ( l <= r ) {
            long long mid = ( l + r ) >> 1LL;
            long long res = 0;
            for ( auto i : ranks ) {
                res += sqrt(mid/i);
            }
            if ( res >= cars ) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
