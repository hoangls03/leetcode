class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector<int> > vt(n,vector<int>(m,0));
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < m ; ++j ) {
                vt[i][j] = matrix[j][i];
            }
        }
        return vt;
    }
};
