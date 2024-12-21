class Solution {
public:
    long long travel( vector<vector<int>>& g, vector<int>& values, int k, int u, vector<int>& vis, int& ans ) {
        vis[u] = 1;
        long long sum = values[u];
        for ( auto v : g[u] ) {
            if ( !vis[v] ) {
                sum += travel(g,values,k,v,vis,ans);
                sum %= k;
            }
        }
        if ( sum % k == 0 ) {
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        vector<int> vis(n,0);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        travel(g,values,k,0,vis,ans);
        return ans;
    }
};
