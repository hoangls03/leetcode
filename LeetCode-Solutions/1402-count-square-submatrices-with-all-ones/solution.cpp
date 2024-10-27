class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sum(m,vector<int>(n,0));
        for ( int i = 0 ; i < m ; ++i ) {
            int rowSum = 0;
            for ( int j = 0 ; j < n ; ++j ) {
                rowSum += matrix[i][j];
                if ( i == 0 ) {
                    sum[i][j] = rowSum;
                } else {
                    sum[i][j] = sum[i-1][j] + rowSum;
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                for ( int s = 0 ; s < min(m-i,n-j) ; ++s ) {
                    int topLeft = ( i - 1 >= 0 && j - 1 >= 0 ) ? sum[i-1][j-1] : 0;
                    int left = ( j - 1 >= 0 ) ? sum[i+s][j-1] : 0;
                    int top = ( i - 1 >= 0 ) ? sum[i-1][j+s] : 0;
                    if ( sum[i+s][j+s] - left - top + topLeft == (s+1)*(s+1) ) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
