#define ii pair<int,int>
#define fi first
#define se second
const int oo = 1e9;
class Solution {
public:
    vector<ii> g[105];
    int d[105];
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    void dijkstra(int x, int n)
    {
        for (int i = 0; i <= n; i++)
            d[i] = oo;
        d[x] = 0;
        pq.push(ii(0, x));
        while (pq.size())
        {
            int u = pq.top().se;
            int du = pq.top().fi;
            pq.pop();
            if (du != d[u])
                continue;
            for (int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i].se;
                int uv = g[u][i].fi;
                if (d[v] > du + uv)
                {
                    d[v] = du + uv;
                    pq.push(ii(d[v], v));
                }
                //cout<<u<<" "<<v<<'\n';
            }
        }
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        for ( int i = 0 ; i <= 100 ; ++i ) {
            g[i].clear();
        }
        vector<vector<int>> saved;
        vector<int> mark(n*n,0);
        for ( int i = 0 ; i < edges.size() ; ++i ) {
            auto e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            if ( w == -1 ) {
                mark[i] = 1;
            } else {
                g[u].push_back({w,v});
                g[v].push_back({w,u});
            }
        }
        dijkstra(source,n);
        vector<vector<int>> ans;
        int temp = d[destination];
        //cout<<0<<'\n';
        if ( temp < target ) return ans;
        if ( temp == target ) {
            for ( auto& e : edges ) {
                if ( e[2] == -1 ) e[2] = target + 1;
            }
            return edges;
        }
        for ( int i = 0 ; i < edges.size() ; ++i ) {
            if ( mark[i] == 1 ) {
                edges[i][2] = 1;
                auto e = edges[i];
                int u = e[0], v = e[1], w = e[2];
                g[u].push_back({w,v});
                g[v].push_back({w,u});
            }
        }
        dijkstra(source,n);
        //cout<<1<<'\n';
        if ( d[destination] > target ) return ans;
        //cout<<d[destination]<<" "<<"here"<<'\n';
        int diff = target - d[destination];
        for ( int i = 0 ; i < edges.size() ; ++i ) {
            if ( mark[i] == 1 ) {
                edges[i][2] += diff;
                auto e = edges[i];
                for ( auto& v : g[e[0]] ) {
                    if ( v.se == e[1] ) {
                        v.fi = e[2];
                        break;
                    }
                }
                for ( auto& v : g[e[1]] ) {
                    if ( v.se == e[0] ) {
                        v.fi = e[2];
                        break;
                    }
                }
                dijkstra(source,n);
                diff = target - d[destination];
                //cout<<"debug "<<d[destination]<<" "<<e[0]<<" "<<e[1]<<" "<<e[2]<<'\n';
                if ( d[destination] == target ) {
                    return edges;
                }
            }
        }
        //cout<<2<<'\n';
        return ans;
    }
};
