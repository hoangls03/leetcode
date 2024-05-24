class Solution {
public:
    void travel( int u, vector<vector<int>>& edge, vector<int>& height, vector<int>& num_sub ) {
        num_sub[u]++;
        for ( auto v : edge[u] ) {
            if ( v != u && height[v] == -1 ) {
                height[v] = height[u] + 1;
                travel(v,edge,height,num_sub);
                num_sub[u] += num_sub[v];
            }
        }
    }
    void find_ans( int u, int n, vector<vector<int>>& edge, vector<int>& num_sub, vector<int>& ans) {
        for ( auto v : edge[u] ) {
            if ( v != u && ans[v] == -1 ) {
                ans[v] = ans[u] - num_sub[v] + n - num_sub[v];
                find_ans(v,n,edge,num_sub,ans);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edge(n);
        for ( auto e : edges ) {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        vector<int> num_sub(n,0);
        vector<int> height(n,-1);
        vector<int> ans(n,-1);
        height[0] = 0;
        ans[0] = 0;
        travel(0,edge,height,num_sub);
        for ( int i = 0 ; i < n ; ++i ) {
            ans[0] += height[i];
        }
        find_ans(0,n,edge,num_sub,ans);
        return ans;
    }
};
