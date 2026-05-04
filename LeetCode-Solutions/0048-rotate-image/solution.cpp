class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < n/2 ; ++i ) {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        for ( int k = 0 ; k < 2*n ; ++k ) {
            for ( int i = 0 ; i < n ; ++i ) {
                if ( k - i < i && k - i >= 0 ) {
                    swap(matrix[i][k-i],matrix[k-i][i]);
                }
            }
        }
    }
};
