class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        for ( int i = 2 ; i <= n ; ++i ) {
            int temp = n/i;
            int mod = n%i;
            int res = 1;
            for ( int j = 1 ; j <= i ; ++j ) {
                if ( mod ) {
                    res *= (temp+1);
                    mod--;
                } else {
                    res *= temp;
                }
            }
            ans = max(ans,res);
        }
        return ans;
    }
};
