const int oo = 1e9 + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int> dp(high+1,0);
        dp[zero]++;
        dp[one]++;
        for ( int i = 0 ; i <= high ; ++i ) {
            if ( i + one <= high ) dp[i+one] = (dp[i+one] + dp[i])%oo;
            if ( i + zero <= high ) dp[i+zero] = (dp[i+zero] + dp[i])%oo;
        }
        for ( int i = low ; i <= high ; ++i ) {
            ans = (ans + dp[i])%oo;
        }
        return ans;
    }
};
