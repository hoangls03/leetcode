class Solution {
public:
    int kthFactor(int n, int k) {
        int mark[n+1];
        for ( int i = 1 ; i <= n ; ++i ) {
            mark[i] = -1;
        }
        int count = 0;
        for ( int i = 1 ; i <= trunc(sqrt(n)) ; ++i ) {
            if ( n % i == 0 ) mark[++count] = i;
        }
        for ( int i = trunc(sqrt(n)) ; i >= 1 ; --i ) {
            if ( n/i != i && n % i == 0 ) mark[++count] = n/i;
        }
        if ( k > n ) return -1;
        return mark[k];
    }
};
