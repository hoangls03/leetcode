class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int neg = 0,num = 1e9;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                ans += abs(matrix[i][j]);
                neg += (matrix[i][j] < 0 );
                int temp = abs(matrix[i][j]);
                num = min(num,temp);
            }
        }
        if (neg & 1) ans -= 2*num;
        return ans;
    }
};
