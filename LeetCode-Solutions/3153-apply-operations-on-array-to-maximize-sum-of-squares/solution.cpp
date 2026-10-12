const int oo = 1e9 + 7;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(30,0);

        for ( auto i : nums ) {
            for ( int j = 0 ; j < 30 ; ++j ) {
                if ( (i >> j) & 1 ) {
                    bit[j]++;
                }
            }
        }

        long long ans = 0;
        for ( int i = 0 ; i < k ; ++i ) {
            long long cur = 0;
            for ( int j = 29 ; j >= 0 ; --j ) {
                if ( bit[j] > 0 ) {
                    cur |= (1LL << j);
                    bit[j]--;
                }
            }
            ans += cur*cur%oo;
            ans %= oo;
        }
        return ans;
    }
};
