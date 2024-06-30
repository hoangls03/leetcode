class Solution {
public:
    int parent[100005];
    int root ( int u ) {
        if ( parent[u] != u ) parent[u] = root(parent[u]);
        return parent[u];
    }
    void join( int x, int y ) {
        int u = root(x);
        int v = root(y);
        parent[v] = u;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> mark(m,0);
        for ( int i = 1 ; i <= n ; ++i ) {
            parent[i] = i;
        }
        for ( int i = 0 ; i < m ; ++i ) {
            if ( edges[i][0] == 3 ) {
                int x = edges[i][1];
                int y = edges[i][2];
                int u = root(x);
                int v = root(y);
                if ( u != v ) {
                    join(x,y);
                    mark[i] = 1;
                }
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            if ( edges[i][0] == 1 ) {
                int x = edges[i][1];
                int y = edges[i][2];
                int u = root(x);
                int v = root(y);
                if ( u != v ) {
                    join(x,y);
                    mark[i] = 1;
                }
            }
        }
        int root_node = root(1);
        for ( int i = 2 ; i <= n ; ++i ) {
            if ( root(i) != root_node ) {
                return -1;
            }
        }
        for ( int i = 1 ; i <= n ; ++i ) {
            parent[i] = i;
        }
        for ( int i = 0 ; i < m ; ++i ) {
            if ( mark[i] == 1 && edges[i][0] == 3 ) {
                int x = edges[i][1];
                int y = edges[i][2];
                int u = root(x);
                int v = root(y);
                if ( u != v ) {
                    join(x,y);
                }
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            if ( mark[i] != 1 && edges[i][0] != 1 ) {
                int x = edges[i][1];
                int y = edges[i][2];
                int u = root(x);
                int v = root(y);
                if ( u != v ) {
                    join(x,y);
                    mark[i] = 1;
                }
            }
        }
        root_node = root(1);
        for ( int i = 2 ; i <= n ; ++i ) {
            if ( root(i) != root_node ) {
                return -1;
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            if ( mark[i] == 0 ) {
                ans++;
                //cout<<i<<" ";
            }
        }
        return ans;
    }
};
