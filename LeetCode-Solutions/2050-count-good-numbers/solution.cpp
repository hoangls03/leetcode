const int oo = 1e9 + 7;
class Solution {
public:
    long long pw(long long a, long long b, int c ) {
        if ( b == 0 ) return 1;
        long long p = pw(a,b/2,c);
        p = p*p%c;
        if ( b & 1 ) p = p*a%c;
        return p;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1)/2;
        long long odd = n/2;
        long long ans = 1LL*pw(5,even,oo)*pw(4,odd,oo)%oo;
        return ans;
    }
};
