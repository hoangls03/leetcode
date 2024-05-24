class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if ( n == 1 ) return {0};
        vector<int> g[n];
        vector<int> degree(n,0);
        for ( auto e : edges ) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for ( int e = 0 ; e < n ; ++e ) {
            if ( degree[e] == 1 ) q.push(e);
        }
        int num_node = n;
        while ( num_node > 2 ) {
            num_node -= q.size();
            int q_size = q.size();
            for ( int k = 0 ; k < q_size ; ++k ) {
                int e = q.front();
                q.pop();
                
                for ( int i = 0 ; i < g[e].size() ; ++i ) {
                    int v = g[e][i];
                    degree[v]--;
                    if ( degree[v] == 1 ) q.push(v);
                }
            }
        }
        vector<int> ans;
        while ( q.size() ) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
