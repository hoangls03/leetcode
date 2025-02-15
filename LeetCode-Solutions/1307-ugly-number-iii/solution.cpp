#define ii pair<long long,long long>
#define fi first
#define se second
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lcmAB = (long long)a*b/__gcd(a,b);
        long long lcmAC = (long long)a*c/__gcd(a,c);
        long long lcmBC = (long long)b*c/__gcd(b,c);
        long long gcdBC = __gcd(b,c);
        long long lcmABC = (long long)a*lcmBC/__gcd((long long)a,lcmBC);
        long long l = 1;
        long long r = 2*1e9;
        long long ans = r;
        if ( a != b && a != c && b != c ) {
            while ( l <= r ) {
                long long mid = ( l + r ) >> 1;
                long long temp = mid/a + mid/b + mid/c - mid/lcmAB - mid/lcmAC - mid/lcmBC + mid/lcmABC;
                if ( temp >= n ) {
                    r = mid - 1;
                    ans = min(mid,ans);
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        }
        if ( a == b && b == c ) {
            return a*n;
        }
        if ( a == b ) {
            b = c;
        }
        lcmAB = (long long)a*b/__gcd(a,b);
        while ( l <= r ) {
            long long mid = ( l + r ) >> 1;
            long long temp = mid/a + mid/b - mid/lcmAB;
            if ( temp >= n ) {
                r = mid - 1;
                ans = min(mid,ans);
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
