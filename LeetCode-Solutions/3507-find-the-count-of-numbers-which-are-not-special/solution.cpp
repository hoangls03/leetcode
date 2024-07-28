class Solution {
public:
    bool check_prime(int n) {
        if ( n <= 1 ) return false;
        if ( n == 2 ) return true;
        for ( int i = 2 ; i <= sqrt(n) ; ++i ) 
            if ( n % i == 0 ) return false;
        return true;
    }
    int nonSpecialCount(int l, int r) {
        int count = 0;
        int ans = r - l + 1;
        for ( int i = 2 ; i <= sqrt(r) ; ++i ) {
            if ( i*i >= l && i*i <= r && check_prime(i)) {
                count++;
            }
        }
        ans = ans - count;
        return ans;
    }
};
