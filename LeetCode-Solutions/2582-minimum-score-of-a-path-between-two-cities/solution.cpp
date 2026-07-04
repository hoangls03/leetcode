class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = 1e9;
        vector<vector<int>> g(n + 1);
        for ( auto e : roads ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n + 1);
        queue<int> q;
        q.push(1);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( !vis[v] ) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        for ( auto e : roads ) {
            if ( vis[e[0]] ) {
                ans = min(ans,e[2]);
            }
        }
        return ans;
    }
};
