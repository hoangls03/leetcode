#define ii pair<int,int>
#define fi first
#define se second
const int oo = 1e9;
class Solution {
public:
    typedef struct {
        int src;
        int cost;
        int stop;
    } st;
    void BFS( int x , int (&d)[105][105], vector<ii> (&g)[105] , int k) {
        queue<st> q;
        d[x][0] = 0;
        q.push(st(x,0,0));
        while ( q.size() ) {
            int u = q.front().src;
            int du = q.front().cost;
            int stop = q.front().stop;
            q.pop();
            if ( stop > k ) continue;
            for ( auto i : g[u] ) {
                int v = i.fi;
                int uv = i.se;
                //cout<<v<<" "<<du + uv<<" "<<d[v][stop+1]<<" "<<stop<<'\n';
                if ( d[v][stop + 1] > du + uv ) {
                    d[v][stop+1] = du + uv;
                    //cout<<d[v][stop+1]<<" "<<v<<" "<<stop+1<<'\n';
                    q.push(st(v,du+uv,stop+1));
                }
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int d[105][105];
        vector<ii> g[105];
        for ( int i = 0 ; i < n ; ++i ) {
            g[i].clear();
        }
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j <= k+1 ; ++j ) {
                d[i][j] = oo;
            }
        }
        for ( int i = 0 ; i < flights.size() ; ++i ) {
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        BFS(src,d,g,k);
        int ans = oo;
        for ( int i = 0 ; i <= k+1 ; ++i ) {
            ans = min(ans,d[dst][i]);
        }
        ans = ( ans == oo ) ? -1 : ans;
        return ans;
    }
};
