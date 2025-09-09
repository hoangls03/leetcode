const int oo = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> mark(n + 1,0);
        long long ans = 0;
        mark[1] = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            for ( int j = i + delay ; j < min(i + forget,n + 1) ; ++j ) {
                mark[j] = (mark[j] + mark[i])%oo;
            }
            if ( i + forget > n ) ans = (ans + mark[i])%oo;
        }
        return ans;
    }
};
