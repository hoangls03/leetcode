#define ii pair<long long,int> 
#define fi first
#define se second
const int MOD = 1e9 + 7;
const long long oo = 1e15;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ii>> g(n);
        for ( auto r : roads ) {
            g[r[0]].push_back({r[2],r[1]});
            g[r[1]].push_back({r[2],r[0]});
        }
        vector<long long> d(n,oo);
        vector<int> ways(n,0);
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        d[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while ( pq.size() ) {
            long long du = pq.top().fi;
            int u = pq.top().se;
            pq.pop();

            if ( du > d[u] ) continue;

            for( auto i : g[u] ) {
                int uv = i.fi;
                int v = i.se;
                if ( du + uv < d[v] ) {
                    d[v] = du + uv;
                    ways[v] = ways[u];
                    pq.push({d[v],v});
                } else if ( du + uv == d[v] ) {
                    ways[v] = ( ways[v] + ways[u] ) % MOD;
                }
            }

        }
        return ways[n-1];        
    }
};
