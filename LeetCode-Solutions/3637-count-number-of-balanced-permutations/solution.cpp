const int oo = 1e9 + 7;
class Solution {
public:
    long long power( int a, int b ) {
        if ( b == 1 ) return a;
        long long p = power(a,b/2)%oo;
        p = p*p%oo;
        if ( b & 1 ) p = p*a%oo;
        return p; 
    }
    int countBalancedPermutations(string num) {
        int n = num.size();
        int sum = 0;
        for ( auto d : num ) {
            sum += (d - '0');
        }
        if ( sum & 1 ) return 0;
        sum /= 2;
        int half = n/2;
        vector<vector<int>> dp(sum + 1,vector<int>(half + 1,0));
        vector<int> fact(n+1);
        fact[0] = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            fact[i] = 1LL*fact[i-1] * i % oo;
        }
        vector<int> count(10,0);
        dp[0][0] = 1;
        for ( auto d : num ) {
            d -= '0';
            count[d]++;
            for ( int i = sum ; i >= d ; --i ) {
                for ( int j = half ; j >= 1 ; --j ) {
                    dp[i][j] = (dp[i][j] + dp[i - d][j-1])%oo;
                }
            }
        }

        int ans = dp[sum][half];
        ans = (1LL*ans*fact[half]%oo)*fact[n - half]%oo;
        for ( auto i : count ) {
            if ( i != 0 ) {
                ans = 1LL*ans*power(fact[i],oo-2)%oo;
            }
        }
        return ans;
    }
};
