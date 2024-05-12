class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-2);
        for ( int i = 0 ; i <= m - 3 ; ++i ) {
            for ( int j = 0 ; j <= n - 3 ; ++j ) {
                int temp = 0;
                for ( int u = i ; u < i + 3 ; ++u ) {
                    for ( int v = j ; v < j + 3 ; ++v ) {
                        temp = max(temp,grid[u][v]);
                    }
                }
                ans[i].push_back(temp);
            }
        }
        return ans;
    }
};
