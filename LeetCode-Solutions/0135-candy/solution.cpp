class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> mark(n,0);
        vector<vector<int>> g(n);
        vector<int> d(n,1);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( i - 1 >= 0 ) {
                if ( ratings[i] > ratings[i-1] ) {
                    g[i-1].push_back(i);
                    mark[i]++;
                }
            }
            if ( i + 1 < n && ratings[i] > ratings[i+1] ) {
                g[i+1].push_back(i);
                mark[i]++;
            }
        }
        queue<int> q;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mark[i] == 0 ) {
                q.push(i);
            }
        }
        while ( q.size() ) {
            int u = q.front();
            q.pop();
            for ( auto v : g[u] ) {
                d[v] = max(d[v],d[u] + 1);
                mark[v]--;
                if ( mark[v] == 0 ) {
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            ans += d[i];
        }
        return ans;
    }
};
