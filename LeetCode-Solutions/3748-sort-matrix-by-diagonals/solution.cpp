class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mark(2*n);
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                mark[i - j + n].push_back(grid[i][j]);
            }
        }
        for ( int i = 0 ; i < 2*n ; ++i ) {
            if ( i >= n ) sort(mark[i].begin(),mark[i].end());
            else sort(mark[i].rbegin(),mark[i].rend());
        }
        vector<vector<int>> ans;
        for ( int i = 0 ; i < m ; ++i ) {
            vector<int> vt;
            for ( int j = 0 ; j < n ; ++j ) {
                vt.push_back(mark[i-j+n][mark[i-j+n].size()-1]);
                mark[i-j+n].pop_back();
            }
            ans.push_back(vt);
        }
        return ans;
    }
};
