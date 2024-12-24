class Solution {
public:
    int findDiameter(vector<vector<int>>& edges ) {
        int n = edges.size() + 1;
        vector<int> deg(n,0);
        vector<vector<int>> g(n);
        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( deg[i] == 1 ) q.push(i);
        }
        int numNode = n;
        int dia = 0;
        while ( numNode > 2 ) {
            dia++;
            int size = q.size();
            numNode -= size;
            for ( int i = 0 ; i < size ; ++i ) {
                auto u = q.front();
                q.pop();
                for ( auto v : g[u] ) {
                    deg[v]--;
                    if ( deg[v] == 1 ) q.push(v);
                }
            }
        }
        return ( numNode == 2 ) ? 2*dia + 1 : 2*dia;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int ans1 = findDiameter(edges1);
        int ans2 = findDiameter(edges2);
        int ans = (ans1 + 1)/2 + (ans2 + 1)/2 + 1;
        ans = max({ans,ans1,ans2});
        return ans;
    }
};
