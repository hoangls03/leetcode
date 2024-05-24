class Solution {
public:
    void BFS( int source, vector<vector<int>>& g, vector<bool>& check ) {
        queue<int> q;
        q.push(source);
        check[source] = true;
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( !check[v] ) {
                    q.push(v);
                    check[v] = true;
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> g(n);
        for ( auto i : edges ) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<bool> check(n,false);
        BFS(source,g,check);
        return check[destination];
    }
};
