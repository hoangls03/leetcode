class Solution {
public:
    bool valid(vector<vector<int>>& g, int u, vector<int>& color ) {
        for ( auto v : g[u]) {
            if ( color[v] == color[u] ) return false;

            if ( color[v] == -1 ) {
                color[v] = ( color[u] + 1 )%2;
                if ( !valid(g,v,color) ) return false;
            }
        }
        return true;
    }
    int path( vector<vector<int>>& g, int u, int n ) {
        queue<int> q;
        vector<bool> vis(n+1,false);

        q.push(u);
        vis[u] = true;
        int dis = 0;
        while ( q.size() ) {
            int m = q.size();
            for ( int i = 0 ; i < m ; ++i ) {
                u = q.front();
                for ( auto v : g[u] ) {
                    if ( !vis[v] ) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
                q.pop();
            }
            dis++;
        }
        return dis;
    }
    int findGroup(vector<vector<int>>& g, int u, vector<int>&d, vector<bool>& vis ) {
        int res = d[u];
        vis[u] = true;
        for ( auto v : g[u] ) {
            if ( !vis[v] ) {
                res = max(res,findGroup(g,v,d,vis));
            }
        }
        return res;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> color(n+1,-1);
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( color[i] == -1 ) {
                color[i] = 0;
                if ( !valid(g,i,color) ) return -1;
            }
        }
        vector<int> d(n+1);
        for ( int i = 1 ; i <= n ; ++i ) {
            d[i] = path(g,i,n);
        }

        int ans = 0;
        vector<bool> vis(n+1,false);
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( !vis[i] ) {
                ans += findGroup(g,i,d,vis);
            }
        }
        return ans;
    }
};
