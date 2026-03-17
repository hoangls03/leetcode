class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> val(m,vector<int>(n,0));
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                val[i][j] = (i > 0) ? val[i - 1][j] : 0;
                val[i][j] = (matrix[i][j] == 1) ? val[i][j] + 1 : 0; 
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            sort(val[i].begin(),val[i].end());
            for ( int j = 0 ; j < n ; ++j ) {
                ans = max(ans,val[i][j] * (n - j));
            }
        }
        return ans;
    }
};
