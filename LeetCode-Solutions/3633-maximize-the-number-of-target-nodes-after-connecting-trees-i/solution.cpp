class Solution {
public:
    void DFS( vector<vector<int>>& g, vector<vector<int>>& d, int root, int par, int u) {
        for ( auto v : g[u] ) {
            if ( v != par ) {
                d[root][v] = d[root][u] + 1;
                DFS(g,d,root,u,v);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> g(n);
        vector<vector<int>> g1(m);
        for ( auto e : edges1 ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for ( auto e : edges2 ) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        vector<vector<int>> d(n,vector<int>(n,0));
        vector<vector<int>> d1(m,vector<int>(m,0));
        for ( int i = 0 ; i < n ; ++i ) {
            DFS(g,d,i,i,i);
        }
        for ( int i = 0 ; i < m ; ++i ) {
            DFS(g1,d1,i,i,i);
        }
        int count = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            int tmp = 0;
            for ( int j = 0 ; j < m ; ++j ) {
                if ( d1[i][j] <= k - 1 ) {
                    tmp++;
                }
            }
            count = max(count,tmp);
        }
        vector<int> res;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ans = count;
            for ( int j = 0 ; j < n ; ++j ) {
                if ( d[i][j] <= k ) {
                    ans++;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
