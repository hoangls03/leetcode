#define ii pair<int,double>
#define fi first
#define se second
class Solution {
public:
    void BFS( vector<vector<ii>>& g, vector<double>& d, int& start ) {
        queue<int> q;
        q.push(start);
        d[start] = 1;
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto& v : g[u] ) {
                if ( d[v.fi] < d[u]*v.se ) {
                    d[v.fi] = d[u]*v.se;
                    q.push(v.fi);
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> d(n,0);
        vector<vector<ii>> g(n);
        for ( int i = 0 ; i < edges.size() ; ++i ) {
            auto e = edges[i];
            g[e[0]].push_back({e[1],succProb[i]});
            g[e[1]].push_back({e[0],succProb[i]});
        }
        BFS(g,d,start_node);
        return d[end_node];
    }
};
