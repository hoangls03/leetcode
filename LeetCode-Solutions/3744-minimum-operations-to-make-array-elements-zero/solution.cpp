class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for ( auto q : queries ) {
            long long prev = q[0];
            long long res = 0,pos = 0;
            for ( int i = 1 ; i <= 16 ; ++i ) {
                long long tmp = (1LL << (2*i));
                if ( tmp > q[0] && tmp <= q[1] ) {
                    res += (tmp - prev)*i;
                    prev = tmp;
                }
                if ( tmp <= q[1] ) {
                    pos = i;
                }
            }
            if ( q[1] >= prev ) {
                res += (q[1] - prev + 1)*(pos + 1);
            }
            ans += (res + 1)/2;
        }
        return ans;
    }
};
