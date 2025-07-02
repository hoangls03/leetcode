const int oo = 1e9 + 7;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size();
        if ( n < k ) return 0;
        int count = 1;
        vector<long long> dp(k,0);
        dp[0] = 1;
        int m = k - 1;
        word += "$";
        long long ans = 1;
        vector<int> counts;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( word[i] == word[i - 1] ) {
                count++;
            } else {
                counts.push_back(count);
                count = 1;
            }
        }
        for ( auto count : counts ) {
            ans = ans*count%oo;
        }
        if ( counts.size() >= k ) {
            return ans;
        }
        vector<int> sum(k,1);
        for ( auto count : counts ) {
            vector<int> f(k);
            for ( int i = 1 ; i < k ; ++i ) {
                f[i] = sum[i-1];
                if ( i - count - 1 >= 0 ) {
                    f[i] = (f[i] - sum[i - count - 1] + oo)%oo;
                }
            }
            vector<int> g(k);
            g[0] = f[0];
            for ( int i = 1 ; i < k ; ++i ) {
                g[i] = (g[i-1] + f[i])%oo;
            }
            for ( int i = 0 ; i < k ; ++i ) {
                dp[i] = f[i];
                sum[i] = g[i];
            }
        }
        ans = (ans - sum[m] + oo)%oo;
        return ans;
    }
};
