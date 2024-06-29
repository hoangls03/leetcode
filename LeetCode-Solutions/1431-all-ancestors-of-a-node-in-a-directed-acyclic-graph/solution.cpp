class Solution {
public:
    void DFS(int root, int u, vector<vector<int>>& neighbor, vector<vector<int>>& ans, vector<int>& mark ) {
        for ( int v : neighbor[u] ) {
            if ( mark[v] == 0 ) {
                ans[root].push_back(v);
                mark[v] = 1;
                DFS(root,v,neighbor,ans,mark);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> neighbor(n);
        vector<vector<int>> ans(n);
        vector<int> mark(n,0);
        for ( int i = 0 ; i < edges.size() ; ++i ) {
            int u = edges[i][0];
            int v = edges[i][1];
            neighbor[v].push_back(u);
        }
        
        for ( int i = 0 ; i < n ; ++i ) {
            if ( ans[i].size() == 0 ) {
                mark[i] = 1;
                DFS(i,i,neighbor,ans,mark);
                mark[i] = 0;
                for ( auto v : ans[i] ) {
                    mark[v] = 0;
                }
                sort(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};
