#define ii pair<long long,long long>
#define fi first
#define se second
const long long oo = 1e18;
class Solution {
public:
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    void dijkstra( int x , vector< vector<long long> > &d , vector<ii> g[])
    {
        for (int i = 0; i <= 26; i++)
            d[x][i] = oo;
        d[x][x] = 0;
        pq.push(ii(0, x));
        while (pq.size())
        {
            int u = pq.top().se;
            int du = pq.top().fi;
            pq.pop();
            if (du != d[x][u])
                continue;
            for (int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i].se;
                int uv = g[u][i].fi;
                if (d[x][v] > du + uv)
                {
                    d[x][v] = du + uv;
                    pq.push(ii(d[x][v], v));
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector< vector<long long> > d(30,vector<long long> (30,0));
        vector<ii> g[30];
        for ( int i = 0 ; i < changed.size() ; ++i ) {
            g[original[i]-'a'].push_back(ii(cost[i],changed[i]-'a'));
        }
        for ( int i = 0 ; i < 26 ; ++i ) {
            dijkstra(i,d,g);
        }
        long long ans = 0;
        for ( int i = 0 ; i < source.size() ; ++i ) {
            if ( d[source[i]-'a'][target[i]-'a'] == oo ) return -1;
            //cout << d[source[i]-'a'][target[i]-'a'] << " " << source[i] << " " << target[i] << '\n';
            ans += d[source[i]-'a'][target[i]-'a']; 
        }
        d.clear();
        for ( int i = 0  ; i < 26 ; ++i ) g[i].clear();
        return ans;
    }
};
