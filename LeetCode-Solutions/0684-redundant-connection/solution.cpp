class Solution {
public:
    int root ( int u, vector<int>& cha ) {
        if ( cha[u] != u ) cha[u] = root(cha[u],cha);
        return cha[u];
    }
    void join( int  x , int  y, vector<int>& cha) {
        int  u = root(x,cha);
        int  v = root(y,cha);
        cha[v] = u;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> cha(n + 1);
        for ( int i = 0 ; i <= n ; ++i ) {
            cha[i] = i;
        }
        for ( auto e : edges ) {
            int u = root(e[0],cha);
            int v = root(e[1],cha);
            if ( u == v ) {
                return e;
            } else {
                join(e[0],e[1],cha);
            }
        }
        return {};
    }
};
