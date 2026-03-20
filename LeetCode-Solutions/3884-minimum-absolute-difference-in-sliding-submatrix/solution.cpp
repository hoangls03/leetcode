class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans;
        for ( int i = 0 ; i < m - k + 1; ++i ) {
            vector<int> row;
            for ( int j = 0 ; j < n - k + 1; ++j ) {
                vector<int> save;
                for ( int u = i ; u < i + k ; ++u ) {
                    for ( int v = j ; v < j + k ; ++v ) {
                        save.push_back(grid[u][v]);
                    }
                }
                sort(save.begin(),save.end());
                int res = abs(save[save.size() - 1] - save[0]);
                for ( int u = 1 ; u < save.size() ; ++u ) {
                    if ( save[u] != save[u-1] ) {
                        int tmp = abs(save[u] - save[u-1]);
                        res = min(res,tmp);
                    }
                }
                row.push_back(res);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
