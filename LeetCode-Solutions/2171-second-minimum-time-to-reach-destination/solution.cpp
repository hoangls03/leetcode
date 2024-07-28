#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    void BFS( vector<vector<int>>& g, vector<int>& d, vector<int>& d2 ) {
        queue<ii> q;
        q.push({1,0});
        d[1] = 0;
        while ( q.size() ) {
            int u = q.front().fi;
            int du = q.front().se;
            q.pop();
            for ( auto v : g[u] ) {
                int dis = du + 1;
                
                if ( dis < d[v] ) {
                    d2[v] = d[v];
                    d[v] = dis;
                    q.push({v,dis});
                } else if ( dis > d[v] ) {
                    if ( dis < d2[v] ) {
                        d2[v] = dis;
                        q.push({v,dis});
                    }
                }
            }
        }
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            g[u].pb(v);
            g[v].pb(u);
        }

        vector<int> d(n + 1,1e9);
        vector<int> d2(n + 1,1e9);
        BFS(g,d,d2);

        int ans = 0;
        for ( int i = 1 ; i <= d2[n] ; ++i ) {
            int temp = ans/change;
            if ( temp & 1 ) ans = (temp+1)*change;
            ans += time;
        }
        return ans;
    }
};
