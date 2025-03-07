class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> mark(right + 1,0);
        mark[1] = 1;
        for ( int i = 2 ; i*i <= right ; ++i ) {
            if ( mark[i] == 0 ) {
                for ( int j = i*i ; j <= right ; j += i ) {
                    mark[j] = 1;
                }
            }
        }
        vector<int> ans(2,-1);
        int prev = -1;
        int cur = -1;
        int res = 1e9;
        for ( int i = left ; i <= right ; ++i ) {
            if ( mark[i] == 0 ) {
                cur = i;
                if ( prev != -1 ) {
                    if ( cur - prev < res ) {
                        ans[0] = prev;
                        ans[1] = cur;
                        res = cur - prev;
                    }
                }
                prev = cur;
            }
        }
        return ans;
    }
};
