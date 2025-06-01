class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for ( int i = min(limit,n) ; i >= 0 && n - i <= 2*limit ; --i ) {
            long long x = n - i;
            if ( limit <= x ) ans += 2*limit - x + 1;
            else ans += x + 1;
        }
        return ans;
    }
};
