class Solution {
public:
    void DFS( int u, vector<vector<int>>& g, vector<int>& root) {
        for ( auto v : g[u] ) {
            if ( root[v] != root[u] ) {
                root[v] = root[u];
                DFS(v,g,root);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int m = allowedSwaps.size();
        vector<vector<int>> g(n), save(n);
        vector<int> root(n,-1);
        for ( auto e : allowedSwaps ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for ( int i = 0 ; i < n ; ++i ) {
            if ( root[i] == -1 ) {
                root[i] = i;
                DFS(i,g,root);
            }
        }
        map<int,int> mark[n + 1];
        for ( int i = 0 ; i < n ; ++i ) {
            cout<<i<<" "<<root[i]<<'\n';
            mark[root[i]][source[i]]++;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[root[i]][target[i]] > 0 ) {
                mark[root[i]][target[i]]--;
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ans += mark[root[i]][source[i]];
            mark[root[i]][source[i]] = 0;
        }
        return ans;
        
    }
};
