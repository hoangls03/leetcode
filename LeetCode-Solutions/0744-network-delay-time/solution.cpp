#define ii pair<int,int>
#define fi first
#define se second
const int oo = 1e9;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<ii>> g(n + 1);
        for ( auto e : times ) {
            g[e[0]].push_back({e[2],e[1]});
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        vector<int> d(n + 1,oo);
        pq.push({0,k});
        d[k] = 0;
        while ( pq.size()) {
            int u = pq.top().se;
            int du = pq.top().fi;
            pq.pop();

            if ( du != d[u] ) continue;

            for ( auto e : g[u] ) {
                int v = e.se;
                int uv = e.fi;
                if ( du + uv < d[v] ) {
                    d[v] = du + uv;
                    pq.push({d[v],v});
                }
            }
        }

        int ans = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            ans = max(ans,d[i]);
        }
        if ( ans == 1e9 ) ans = -1;
        return ans;
    }
};
