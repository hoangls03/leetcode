class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        int col = 0;
        int val = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            while ( rowSum[i] > 0 ) {
                int temp = min(colSum[col],rowSum[i]);
                ans[i][col] = temp;
                colSum[col] -= temp;
                rowSum[i] -= temp;
                if ( colSum[col] == 0 ) col++;
            }
        }
        return ans;
    }
};
