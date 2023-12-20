class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> oneRow(m,0);
        vector<int> oneCol(n,0);
        int ans = 0;

        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( j == 0 ) oneRow[i] = mat[i][j];
                else oneRow[i] = oneRow[i] + mat[i][j];
            }
        }
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                if ( i == 0 ) oneCol[j] = mat[i][j];
                else oneCol[j] = oneCol[j] + mat[i][j];
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( mat[i][j] == 1 && oneRow[i] == 1 && oneCol[j] == 1 ) ans++;
            }
        }
        return ans;
    }
};
