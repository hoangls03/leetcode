class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = 0;
            int sum = ( i == 0 ) ? 0 : dp[i-1];
            for ( int j = i ; j < min(i + k,n) ; ++j ) {
                temp = max(temp,arr[j]);
                dp[j] = max(dp[j],sum + temp*(j-i+1));
            }
        }
        return dp[n-1];
    }
};
