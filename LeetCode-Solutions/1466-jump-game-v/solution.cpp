class Solution {
public:
    int cal(int u, vector<vector<int>>& g, vector<int>& dp) {
        if ( dp[u] != -1 ) return dp[u];
        dp[u] = 1;
        for ( auto v : g[u] ) {
            dp[u] = max(dp[u], cal(v,g,dp) + 1);
        }
        return dp[u];
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> g(n + 1);
        vector<int> dp(n + 1, -1);
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 1 ; j <= d ; ++j ) {
                if ( i + j < n && arr[i] > arr[i + j]) {
                    g[i].push_back(i+j);
                } else {
                    break;
                }
            }
            for ( int j = 1 ; j <= d ; ++j ) {
                if ( i - j >= 0 && arr[i] > arr[i - j]) {
                    g[i].push_back(i-j);
                } else {
                    break;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ans = max(ans,cal(i,g,dp));
        }
        return ans;

    }
};
