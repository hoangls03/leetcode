class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> deg(n);
        vector<vector<int>> g(n);

        for ( int i = 0 ; i < n ; ++i ) {
            for ( auto u : graph[i] ) {
                g[u].push_back(i);
                deg[i]++;
            }
        }

        queue<int> q;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( deg[i] == 0 ) {
                q.push(i);
            }
        }

        vector<bool> save(n);

        while ( q.size() ) {
            int u = q.front();
            q.pop();
            save[u] = true;

            for ( auto v : g[u] ) {
                deg[v]--;
                if ( deg[v] == 0 ) {
                    q.push(v);
                }
            }
        }

        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( save[i] ) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
