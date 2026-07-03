#define ii pair<long long,int>
#define fi first
#define se second
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int l = 0, r = 1e9;
        int n = online.size();
        if ( n == 0 ) {
            return -1;
        }
        int ans = -1;
        vector<long long> d(n,1e18);
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        vector<vector<ii>> g(n);
        for ( auto e : edges ) {
            g[e[0]].push_back({e[2],e[1]});
        }
        while ( l <= r ) {
            int mid = (l +r)>>1;
            
            for ( int i = 0 ; i <= n - 1 ; ++i ) {
                d[i] = 1e18;
            }

           
            
            
            
            pq.push({0,0});
            d[0] = 0;
            while(pq.size()) {
                auto u = pq.top();
                if ( u.se == n - 1 ) {
                    break;
                }
                pq.pop();
                if ( u.fi != d[u.se] ) {
                    continue;
                }
                if ( u.fi >= k ) {
                    break;
                }
                for ( auto e : g[u.se] ) {
                    int v = e.se, uv = e.fi;
                    if ( online[v] && uv >= mid && d[v] > u.fi + uv ) {
                        d[v] = u.fi + uv;
                        pq.push({d[v],v});
                    }
                }
            }
            while ( pq.size() ) {
                pq.pop();
            }
            if ( d[n-1] <= k ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
