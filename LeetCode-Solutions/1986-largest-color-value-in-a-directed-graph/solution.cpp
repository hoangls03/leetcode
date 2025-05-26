class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> d(n);
        for ( auto e : edges ) {
            g[e[1]].push_back(e[0]);
            d[e[0]]++;
        }
        queue<int> q;
        vector<vector<int>> dp(n,vector<int>('z' + 1,0)); 
        for ( int i = 0 ; i < n ; ++i ) {
            if ( d[i] == 0 ) {
                q.push(i);
                dp[i][colors[i]] = 1;
            }
        }
        
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                for ( int i = 'a' ; i <= 'z' ; ++i ) {
                    dp[v][i] = max(dp[v][i],dp[u][i]);
                }
                dp[v][colors[v]] = max(dp[v][colors[v]],dp[u][colors[v]] + 1);
                d[v]--;
                if ( d[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( d[i] != 0 ) {
                return -1;
            }
            for ( int j = 'a' ; j <= 'z' ; ++j ) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
