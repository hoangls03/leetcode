class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = 0;
        int sum = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            sum += (blocks[i] == 'B');
            if ( i >= k - 1 ) {
                ans = max(ans,sum);
                sum -= (blocks[i - k + 1] == 'B');
            }
        }
        return k - ans;
    }
};
