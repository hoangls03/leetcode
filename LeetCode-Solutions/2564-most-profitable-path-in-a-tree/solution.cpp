class Solution {
public:
    void travel( int s, int goal, vector<vector<int>>& g, vector<int>& d ) {
        for ( auto v : g[s] ) {
            if ( d[v] == -2 ) {
                d[v] = d[s] + 1;
                travel(v,goal,g,d);
            }
        }
    }
    void findPath( int u, vector<vector<int>>& g, vector<int>& d, vector<int>& path ) {
        for ( auto v : g[u] ) {
            if ( d[v] == d[u] - 1 ) {
                path.push_back(v);
                findPath(v,g,d,path);
            }
        }
    }
    void minPath( int u, vector<vector<int>>& g, vector<int>& val, vector<int>& mark, vector<int>& d, vector<int>& amount, vector<int>& dA, vector<int>& leaf ) {
        for ( auto v : g[u] ) {
            if ( dA[v] == -1 ) {
                int cost = amount[v];
                dA[v] = dA[u] + 1;
                if ( mark[v] == 1 ) {
                    if ( dA[v] > d[v] ) {
                        cost = 0;
                    } else if ( dA[v] == d[v] ) {
                        cost /= 2;
                    }
                } 
                val[v] = val[u] + cost;
                minPath(v,g,val,mark,d,amount,dA,leaf);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        vector<int> path;
        vector<vector<int>> g(n+1);
        vector<int> d(n+1,-2);
        vector<int> mark(n+1,0);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        d[bob] = 0;
        travel(bob,0,g,d);
        path.push_back(0);
        findPath(0,g,d,path);
        vector<int> dA(n+1,-1);

        dA[0] = 0;
        for ( auto i : path ) {
            mark[i] = 1;
        }
        vector<int> val(n+1,-1e9 - 1);
        vector<int> leaf;
        val[0] = amount[0];
        minPath(0,g,val,mark,d,amount,dA,leaf);
        int ans = -1e9;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( g[i].size() == 1 ) {
                leaf.push_back(i);
            }
        }
        for ( auto i : leaf ) {
            ans = max(ans,val[i]);
        }
        return ans;
    }
};
