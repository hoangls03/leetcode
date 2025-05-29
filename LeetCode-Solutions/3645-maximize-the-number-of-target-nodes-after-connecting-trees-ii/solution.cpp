class Solution {
public:
    void DFS( int par, int u, vector<vector<int>>& g, vector<vector<int>>& d ) {
        d[u][0] = 1;
        
        for ( auto v : g[u] ) {
            if ( v != par ) {
                d[u][1] = max(0,d[u][1]);
                DFS(u,v,g,d);
                if ( d[v][1] != -1 ) {
                    d[u][0] = max(d[u][0],0);
                    d[u][0] += d[v][1];
                }
                if ( d[v][0] != -1 ) d[u][1] += d[v][0];
            }
        }
    }
    void calNode( int par, int u, vector<vector<int>>& g, vector<vector<int>>& d ) {
        if ( u != 0 ) {
            d[u][0] = d[par][1];
            d[u][1] = d[par][0];
        }
        for ( auto v : g[u] ) {
            if ( v != par ) calNode(u,v,g,d);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int m = edges1.size() + 1;
        int n = edges2.size() + 1;
        vector<vector<int>> d(m,vector<int>(2,-1));
        vector<vector<int>> d1(n,vector<int>(2,-1));
        vector<vector<int>> g(m);
        vector<vector<int>> g1(n);
        for ( auto e : edges1 ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for ( auto e : edges2 ) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        DFS(0,0,g,d);
        DFS(0,0,g1,d1);
        int val = max(d1[0][0],d1[0][1]);

        calNode(0,0,g,d);
        vector<int> ans;
        cout<<val<<'\n';
        for ( int i = 0 ; i < m ; ++i ) {
            d[i][0] = max(d[i][0],0);
            ans.push_back(d[i][0] + val);
        }
        return ans;
    }
};
