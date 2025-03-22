class Solution {
public:
    int root( int u, vector<int>& parent ) {
        if ( parent[u] != u ) {
            parent[u] = root(parent[u],parent);
        }
        return parent[u];
    }
    void join(int a, int b, vector<int>& parent) {
        int u = root(a,parent);
        int v = root(b,parent);
        parent[v] = u;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mark(n,vector<int>(n,0));
        vector<int> parent(n);
        for ( int i = 0 ; i < n ; ++i ) {
            parent[i] = i;
            mark[i][i] = 1;
        }
        for ( auto e : edges ) {
            mark[e[0]][e[1]] = 1;
            mark[e[1]][e[0]] = 1;
            join(e[0],e[1],parent);
        }

        vector<vector<int>> save(n);
        for ( int i = 0 ; i < n ; ++i ) {
            int u = root(i,parent);
            save[u].push_back(i);
        }

        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            bool check = true;
            for ( auto j : save[i] ) {
                for ( auto z : save[i] ) {
                    if ( mark[j][z] == 0 ) {
                        check = false;
                    }
                }
            }
            if ( save[i].size() != 0 ) {
                ans += check;
            }
        }
        
        return ans;
    }
};
