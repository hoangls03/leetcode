class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long l = 1, r = 1e18;
        while ( l <= r ) {
            long long mid = (l + r)>>1LL;
            long long countNum = 0;
            for (int i = 1 ; i < (1<<n) ; ++i ) {
                int num = 0;
                long long prev = 1, tmp = 1;
                for ( int j = 0 ; j < n ; ++j ) {
                    if ( (i >> j) & 1 ) {
                        tmp = __gcd(prev,1LL*coins[j]);
                        prev = coins[j]/tmp * prev;
                        num++;
                    }
                }
                if ( num & 1 ) {
                    countNum += mid/prev;
                } else {
                    countNum -= mid/prev;
                }
            }
            if ( countNum == k ) {
                long long ans = 1;
                for ( auto i : coins ) {
                    long long tmp = mid/i;
                    ans = max(ans,i * tmp);
                }
                return ans;
            }
            if ( countNum < k ) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return 0;
    }
};
