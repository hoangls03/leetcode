class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> save(m + n);
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                save[i+j].push_back(mat[i][j]);
            }
        }
        bool ok = true;
        vector<int> ans;
        for ( int i = 0 ; i < m + n ; ++i ) {
            if ( save[i].size() ) {
                if ( ok ) {
                    reverse(save[i].begin(),save[i].end());
                }
                ok = !ok;
                for ( auto j : save[i] ) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
