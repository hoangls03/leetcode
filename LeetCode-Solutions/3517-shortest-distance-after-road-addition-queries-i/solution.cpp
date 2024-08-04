class Solution {
public:
    void BFS(int n, vector<vector<int>>& g, int& ans ) {
        vector<int> d(n,1e9);
        d[0] = 0;
        queue<int> q;
        q.push(0);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( d[u] + 1 < d[v] ) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        ans = d[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for ( int i = 0 ; i < n - 1; ++i ) {
            g[i].push_back(i+1);
        }
        vector<int> ans;
        for ( auto e : queries ) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            int temp;
            BFS(n,g,temp);
            ans.push_back(temp);

        }
        return ans;
    }
};
