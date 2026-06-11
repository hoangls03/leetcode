const int oo = 1e9 + 7;
class Solution {
public:
    void DFS(int par, int u, vector<vector<int>>& g, vector<vector<int>>& d, vector<int>& height) {
        height[u] = height[par] + 1;
        if ( u != 1 ) {
            d[u][0] = (0LL + d[par][0] + d[par][1])%oo;
            d[u][1] = (0LL + d[par][0] + d[par][1])%oo;
        }
        for ( auto v : g[u] ) {
            if ( v != par ) {
                DFS(u,v,g,d,height);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 2;
        vector<vector<int>> g(n);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<vector<int>> d(n,vector<int>(2,0));
        vector<int> height(n);
        d[1][0] = 1;
        height[0] = 0;
        DFS(0, 1, g, d, height);
        int maxHeight = 0;
        int ans;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( height[i] > maxHeight ) {
                ans = d[i][1];
                maxHeight = height[i];
            }
        }
        return ans;
    }
};
