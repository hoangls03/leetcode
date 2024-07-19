class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> col(n,0);
        vector<int> ans;
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                col[j] = max(col[j],matrix[i][j]);
            }
        }
        for ( int i = 0 ; i < m ; ++i ) {
            int row = matrix[i][0];
            for ( int j = 0 ; j < n ; ++j ) {
                row = min(row,matrix[i][j]);
            }
            for ( int j = 0 ; j < n ; ++j ) {
                if ( matrix[i][j] == row && row == col[j] ) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};
