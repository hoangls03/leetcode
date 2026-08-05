class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n), rg(n);
        vector<int> mark(n);
        for ( auto e : invocations ) {
            g[e[0]].push_back(e[1]);
        }
        for ( int i = 0 ; i < n ; ++i ) {
            mark[i] = 0;
        }
        mark[k] = 1;
        queue<int> q;
        q.push(k);
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( mark[v] == 0 ) {
                    mark[v] = 1;
                    q.push(v);
                }
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 0 ) {
                q.push(i);
            }
        }
        bool ok = true;
        while ( q.size() && ok) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                if ( mark[v] == 1 ) {
                    ok = false;
                    break;
                } else if ( mark[v] == 0 ) {
                    mark[v] = 2;
                    q.push(v);
                }
            }
        }
        vector<int> ans;
        if ( !ok ) {
            for ( int i = 0 ; i < n ; ++i ) {
                ans.push_back(i);
            }
            return ans;
        }
        
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] != 1 ) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
