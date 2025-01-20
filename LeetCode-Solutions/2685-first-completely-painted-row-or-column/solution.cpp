class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m*n+1,0);
        vector<int> col(m*n+1,0);
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                int val = mat[i][j];
                row[val] = i;
                col[val] = j;
            }
        }
        vector<int> markRow(m,0);
        vector<int> markCol(n,0);
        for ( int i = 0 ; i < arr.size() ; ++i ) {
            int val = arr[i];
            markRow[row[val]]++;
            markCol[col[val]]++;
            if ( markRow[row[val]] == n || markCol[col[val]] == m ) {
                return i;
            }
        }
        return 0;
    }
};
