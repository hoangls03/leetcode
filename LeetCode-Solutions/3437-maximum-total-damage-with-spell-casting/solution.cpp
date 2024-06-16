#pragma GCC optimize("O3,unroll-loops")
#define LL long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long ans = 0;
        int n = power.size();
        sort(power.begin(),power.end());
        int pos = -1;
        map<int,int> mp;
        for ( auto i : power ) {
            mp[i]++;
        }
        long long dp[n+5];
        for ( int i = 0 ; i < n ; ++i ) {
            int l = 0;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                if ( power[mid] < power[i]-2 ) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[i] = 1LL*power[i]*mp[power[i]];
            if ( pos != -1 ) dp[i] = max(dp[pos]+power[i]*mp[power[i]],dp[i-1]);
            if ( i > 0 ) dp[i] = max(dp[i],dp[i-1]);
            ans = max(ans,dp[i]);
        }
       
        
        
        return ans;
    }
};
