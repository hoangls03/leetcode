class Solution {
public:
    int DFS( int u, vector<vector<int>>& g, vector<int>& vis, int& ans ) {
        vis[u] = 1;
        vector<int> local;
        int size = 1;
        bool check = true;
        for ( auto v : g[u] ) {
            if ( vis[v] == 0 ) {
                vis[v] = 1;
                int temp = DFS(v,g,vis,ans);
                size += temp;
                local.push_back(temp);
            }
        }
        for ( int i = 1 ; i < local.size() && check ; ++i ) {
            if ( local[i] != local[i-1] ) check = false;
        }
        ans += check;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        vector<int> vis(n,0);
        for ( auto e : edges ) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        DFS(0,g,vis,ans);
        return ans;
    }
};
