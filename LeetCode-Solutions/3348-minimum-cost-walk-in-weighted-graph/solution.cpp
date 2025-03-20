class Solution {
public:
    int root ( int u, vector<int>& parent ) {
        if ( parent[u] != u ) parent[u] = root(parent[u], parent);
        return parent[u];
    }
    void join( int  x , int  y, vector<int>& parent) {
        int  u = root(x, parent);
        int  v = root(y, parent);
        parent[v] = u;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n,0);
        for ( int i = 0 ; i < n ; ++i ) {
            parent[i] = i;
        }
        vector<int> save(n,-1);

        for ( auto e : edges ) {
            int lRoot = root(e[1],parent);
            join(e[0],e[1],parent);
            int tmp = root(e[0],parent);
            save[tmp] = (save[tmp] == -1 ) ? e[2] : save[tmp]&e[2];
            if ( save[lRoot] != -1 ) save[tmp] &= save[lRoot];
        }
        vector<int> ans;
        for ( auto q : query ) {
            int u = root(q[0],parent);
            int v = root(q[1],parent);
            if ( u != v ) {
                ans.push_back(-1);
            } else {
                ans.push_back(save[u]);
            }
        }
        return ans;
    }
};
